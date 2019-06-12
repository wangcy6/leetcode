#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>

#include <omp.h>
#include <math.h>

typedef unsigned long long uint64_t;

void runParallelAllocTest()
{
    // constants
    const int  NUM_ALLOCATIONS = 5000; // alloc's per thread
    const int  NUM_THREADS = 4;       // how many threads?
    const int  NUM_ITERS = NUM_THREADS;// how many overall repetions

    const bool USE_NEW      = true;   // use new or malloc? , seems to make no difference (as it should)
    const bool DEBUG_ALLOCS = false;  // debug output

    // pre store allocation sizes
    const int  NUM_PRE_ALLOCS = 20000;
    const uint64_t MEM_LIMIT = (1024 * 1024) * 256;   // x MB per process
    const size_t MAX_CHUNK_SIZE = 1024 * 1024 * 1;

    srand(1);
    std::vector<size_t> allocations;
    allocations.resize(NUM_PRE_ALLOCS);
    for (int i = 0; i < NUM_PRE_ALLOCS; i++) {
        allocations[i] = rand() % MAX_CHUNK_SIZE;   // use up to x MB chunks
    }


    #pragma omp parallel num_threads(NUM_THREADS)
    #pragma omp for
    for (int i = 0; i < NUM_ITERS; ++i) {
        uint64_t long totalAllocBytes = 0;
        uint64_t currAllocBytes = 0;

        std::deque< std::pair<char*, uint64_t> > pointers;
        const int myId = omp_get_thread_num();

        for (int j = 0; j < NUM_ALLOCATIONS; ++j) {
            // new allocation
            const size_t allocSize = allocations[(myId * 100 + j) % NUM_PRE_ALLOCS ];

            char* pnt = NULL;
            if (USE_NEW) {
                pnt = new char[allocSize];
            } else {
                pnt = (char*) malloc(allocSize);
            }
            pointers.push_back(std::make_pair(pnt, allocSize));

            totalAllocBytes += allocSize;
            currAllocBytes  += allocSize;

            // fill with values to add "delay"
            for (int fill = 0; fill < (int) allocSize; ++fill) {
                pnt[fill] = (char)(j % 255);
            }


            if (DEBUG_ALLOCS) {
                std::cout << "Id " << myId << " New alloc " << pointers.size() << ", bytes:" << allocSize << " at " << (uint64_t) pnt << "\n";
            }

            // free all or just a bit
            if (((j % 5) == 0) || (j == (NUM_ALLOCATIONS - 1))) {
                int frees = 0;

                // keep this much allocated
                // last check, free all
                uint64_t memLimit = MEM_LIMIT;
                if (j == NUM_ALLOCATIONS - 1) {
                    std::cout << "Id " << myId << " about to release all memory: " << (currAllocBytes / (double)(1024 * 1024)) << " MB" << std::endl;
                    memLimit = 0;
                }
                //MEM_LIMIT = 0; // DEBUG

                while (pointers.size() > 0 && (currAllocBytes > memLimit)) {
                    // free one of the first entries to allow previously obtained resources to 'live' longer
                    currAllocBytes -= pointers.front().second;
                    char* pnt       = pointers.front().first;

                    // free memory
                    if (USE_NEW) {
                        delete[] pnt;
                    } else {
                        free(pnt);
                    }

                    // update array
                    pointers.pop_front();

                    if (DEBUG_ALLOCS) {
                        std::cout << "Id " << myId << " Free'd " << pointers.size() << " at " << (uint64_t) pnt << "\n";
                    }
                    frees++;
                }
                if (DEBUG_ALLOCS) {
                    std::cout << "Frees " << frees << ", " << currAllocBytes << "/" << MEM_LIMIT << ", " << totalAllocBytes << "\n";
                }
            }
        } // for each allocation

        if (currAllocBytes != 0) {
            std::cerr << "Not all free'd!\n";
        }

        std::cout << "Id " << myId << " done, total alloc'ed " << ((double) totalAllocBytes / (double)(1024 * 1024)) << "MB \n";
    } // for each iteration

    exit(1);
}

int main(int argc, char** argv)
{
    runParallelAllocTest();

    return 0;
}