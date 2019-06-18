// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME G__Position

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "/Users/swenzel/git/PowerWeek/code/examples/basicrootio/trees_userclass/Position.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *Position_Dictionary();
   static void Position_TClassManip(TClass*);
   static void *new_Position(void *p = 0);
   static void *newArray_Position(Long_t size, void *p);
   static void delete_Position(void *p);
   static void deleteArray_Position(void *p);
   static void destruct_Position(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Position*)
   {
      ::Position *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Position));
      static ::ROOT::TGenericClassInfo 
         instance("Position", "", 3,
                  typeid(::Position), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &Position_Dictionary, isa_proxy, 4,
                  sizeof(::Position) );
      instance.SetNew(&new_Position);
      instance.SetNewArray(&newArray_Position);
      instance.SetDelete(&delete_Position);
      instance.SetDeleteArray(&deleteArray_Position);
      instance.SetDestructor(&destruct_Position);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Position*)
   {
      return GenerateInitInstanceLocal((::Position*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::Position*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *Position_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::Position*)0x0)->GetClass();
      Position_TClassManip(theClass);
   return theClass;
   }

   static void Position_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_Position(void *p) {
      return  p ? new(p) ::Position : new ::Position;
   }
   static void *newArray_Position(Long_t nElements, void *p) {
      return p ? new(p) ::Position[nElements] : new ::Position[nElements];
   }
   // Wrapper around operator delete
   static void delete_Position(void *p) {
      delete ((::Position*)p);
   }
   static void deleteArray_Position(void *p) {
      delete [] ((::Position*)p);
   }
   static void destruct_Position(void *p) {
      typedef ::Position current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Position

namespace {
  void TriggerDictionaryInitialization_libPosition_Impl() {
    static const char* headers[] = {
"/Users/swenzel/git/PowerWeek/code/examples/basicrootio/trees_userclass/Position.h",
0
    };
    static const char* includePaths[] = {
"/Users/swenzel/alisw_new/sw/osx_x86-64/ROOT/v6-16-00-4/include",
"/Users/swenzel/alisw_new/sw/osx_x86-64/ROOT/v6-16-00-4/include",
"/Users/swenzel/git/PowerWeek/code/examples/basicrootio/trees_userclass/build/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libPosition dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$/Users/swenzel/git/PowerWeek/code/examples/basicrootio/trees_userclass/Position.h")))  Position;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libPosition dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "/Users/swenzel/git/PowerWeek/code/examples/basicrootio/trees_userclass/Position.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"Position", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libPosition",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libPosition_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libPosition_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libPosition() {
  TriggerDictionaryInitialization_libPosition_Impl();
}
