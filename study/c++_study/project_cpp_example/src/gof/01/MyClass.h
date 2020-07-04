// MyClass.h
 class MyClassImpl;    // forward declaration
 class MyClass {
 public:
   MyClass();
 ~MyClass();
   int foo();
 private:
   MyClassImpl *m_pImpl;
 };