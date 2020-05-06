// 139.word-break
package main

import (
	"fmt"
)

func wordBreak2(s string, wordDict []string) bool {

	return workdBack(s, wordDict, 0)
}
func workdBack(s string, wordDict []string, start int) bool {

	for cur := start; cur < len(s)-1; cur++ {
          
	}
}
func isExit

/**
func wordBreak1(s string, wordDict []string) bool {

	lenWord := len(s)
	lenDict := len(wordDict)

	if lenWord == 0 || lenDict == 0 {
		return false
	}

	for i := 0; i < lenWord; i++ {
		left := s[0:i]

		for j := 0; j < lenDict; j++ {
			if left == wordDict[j] {
				right := s[i:lenWord]

				for k := 0; k < lenDict; k++ {
					if right == wordDict[k] {
						fmt.Println(left, right)
						return true

					} else {
						if true == wordBreak(right, wordDict) {
							return true
							//左面也是同样判断
						}
					}
				}
			} else {

				//不相等也需要判断
			}

		}
	}

	return false
}**/
func main() {
	//wordDict := []string{"leet", "code"}
	//s := "leetcode"

	wordDict := []string{"apple", "pen"}
	s := "applepenapple"
	fmt.Println(wordBreak(s, wordDict))
}
