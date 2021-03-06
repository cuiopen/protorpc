// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: XmlTest.proto

#ifndef PROTOBUF_XmlTest_2eproto__INCLUDED
#define PROTOBUF_XmlTest_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2004001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/xml/xml_message.h>
// @@protoc_insertion_point(includes)

namespace google {
namespace protobuf {
namespace xml {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_XmlTest_2eproto();
void protobuf_AssignDesc_XmlTest_2eproto();
void protobuf_ShutdownFile_XmlTest_2eproto();

class PbMessage;
class PbXmlTest;

enum PbValueType {
  PB_VALUE_TYPE_NULL = 0,
  PB_VALUE_TYPE_BOOL = 1,
  PB_VALUE_TYPE_INT = 2
};
bool PbValueType_IsValid(int value);
const PbValueType PbValueType_MIN = PB_VALUE_TYPE_NULL;
const PbValueType PbValueType_MAX = PB_VALUE_TYPE_INT;
const int PbValueType_ARRAYSIZE = PbValueType_MAX + 1;

const ::google::protobuf::EnumDescriptor* PbValueType_descriptor();
inline const ::std::string& PbValueType_Name(PbValueType value) {
  return ::google::protobuf::internal::NameOfEnum(
    PbValueType_descriptor(), value);
}
inline bool PbValueType_Parse(
    const ::std::string& name, PbValueType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<PbValueType>(
    PbValueType_descriptor(), name, value);
}
// ===================================================================

class PbMessage : public ::google::protobuf::Message {
 public:
  PbMessage();
  virtual ~PbMessage();
  
  PbMessage(const PbMessage& from);
  
  inline PbMessage& operator=(const PbMessage& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const PbMessage& default_instance();
  
  void Swap(PbMessage* other);
  
  // implements Message ----------------------------------------------
  
  PbMessage* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const PbMessage& from);
  void MergeFrom(const PbMessage& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // xml support -----------------------------------------------------
  
  // Parse a protocol buffer contained in a string.
  bool ParseFromXmlString(const string& data);
  // Like ParseFromXmlString(), but accepts messages that are missing
  // required fields.
  bool ParsePartialFromXmlString(const string& data);
  
  // Serialize the message and store it in the given string.  All required
  // fields must be set.
  bool SerializeToXmlString(string* output) const;
  // Like SerializeToXmlString(), but allows missing required fields.
  bool SerializePartialToXmlString(string* output) const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // required bool b = 1;
  inline bool has_b() const;
  inline void clear_b();
  static const int kBFieldNumber = 1;
  inline bool b() const;
  inline void set_b(bool value);
  
  // required int32 i = 2;
  inline bool has_i() const;
  inline void clear_i();
  static const int kIFieldNumber = 2;
  inline ::google::protobuf::int32 i() const;
  inline void set_i(::google::protobuf::int32 value);
  
  // @@protoc_insertion_point(class_scope:google.protobuf.xml.PbMessage)
 private:
  inline void set_has_b();
  inline void clear_has_b();
  inline void set_has_i();
  inline void clear_has_i();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  bool b_;
  ::google::protobuf::int32 i_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];
  
  friend void  protobuf_AddDesc_XmlTest_2eproto();
  friend void protobuf_AssignDesc_XmlTest_2eproto();
  friend void protobuf_ShutdownFile_XmlTest_2eproto();
  
  void InitAsDefaultInstance();
  static PbMessage* default_instance_;
};
// -------------------------------------------------------------------

class PbXmlTest : public ::google::protobuf::Message {
 public:
  PbXmlTest();
  virtual ~PbXmlTest();
  
  PbXmlTest(const PbXmlTest& from);
  
  inline PbXmlTest& operator=(const PbXmlTest& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const PbXmlTest& default_instance();
  
  void Swap(PbXmlTest* other);
  
  // implements Message ----------------------------------------------
  
  PbXmlTest* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const PbXmlTest& from);
  void MergeFrom(const PbXmlTest& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // xml support -----------------------------------------------------
  
  // Parse a protocol buffer contained in a string.
  bool ParseFromXmlString(const string& data);
  // Like ParseFromXmlString(), but accepts messages that are missing
  // required fields.
  bool ParsePartialFromXmlString(const string& data);
  
  // Serialize the message and store it in the given string.  All required
  // fields must be set.
  bool SerializeToXmlString(string* output) const;
  // Like SerializeToXmlString(), but allows missing required fields.
  bool SerializePartialToXmlString(string* output) const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // required bool b = 1 [default = true];
  inline bool has_b() const;
  inline void clear_b();
  static const int kBFieldNumber = 1;
  inline bool b() const;
  inline void set_b(bool value);
  
  // required int32 i = 2 [default = 123];
  inline bool has_i() const;
  inline void clear_i();
  static const int kIFieldNumber = 2;
  inline ::google::protobuf::int32 i() const;
  inline void set_i(::google::protobuf::int32 value);
  
  // required float f = 3;
  inline bool has_f() const;
  inline void clear_f();
  static const int kFFieldNumber = 3;
  inline float f() const;
  inline void set_f(float value);
  
  // required .google.protobuf.xml.PbValueType e = 4 [default = PB_VALUE_TYPE_BOOL];
  inline bool has_e() const;
  inline void clear_e();
  static const int kEFieldNumber = 4;
  inline google::protobuf::xml::PbValueType e() const;
  inline void set_e(google::protobuf::xml::PbValueType value);
  
  // required .google.protobuf.xml.PbMessage m = 5;
  inline bool has_m() const;
  inline void clear_m();
  static const int kMFieldNumber = 5;
  inline const ::google::protobuf::xml::PbMessage& m() const;
  inline ::google::protobuf::xml::PbMessage* mutable_m();
  inline ::google::protobuf::xml::PbMessage* release_m();
  
  // optional bool b1 = 11 [default = true];
  inline bool has_b1() const;
  inline void clear_b1();
  static const int kB1FieldNumber = 11;
  inline bool b1() const;
  inline void set_b1(bool value);
  
  // optional int32 i1 = 12 [default = 456];
  inline bool has_i1() const;
  inline void clear_i1();
  static const int kI1FieldNumber = 12;
  inline ::google::protobuf::int32 i1() const;
  inline void set_i1(::google::protobuf::int32 value);
  
  // optional float f1 = 13;
  inline bool has_f1() const;
  inline void clear_f1();
  static const int kF1FieldNumber = 13;
  inline float f1() const;
  inline void set_f1(float value);
  
  // optional .google.protobuf.xml.PbValueType e1 = 14 [default = PB_VALUE_TYPE_INT];
  inline bool has_e1() const;
  inline void clear_e1();
  static const int kE1FieldNumber = 14;
  inline google::protobuf::xml::PbValueType e1() const;
  inline void set_e1(google::protobuf::xml::PbValueType value);
  
  // optional .google.protobuf.xml.PbMessage m1 = 15;
  inline bool has_m1() const;
  inline void clear_m1();
  static const int kM1FieldNumber = 15;
  inline const ::google::protobuf::xml::PbMessage& m1() const;
  inline ::google::protobuf::xml::PbMessage* mutable_m1();
  inline ::google::protobuf::xml::PbMessage* release_m1();
  
  // repeated bool bn = 21;
  inline int bn_size() const;
  inline void clear_bn();
  static const int kBnFieldNumber = 21;
  inline bool bn(int index) const;
  inline void set_bn(int index, bool value);
  inline void add_bn(bool value);
  inline const ::google::protobuf::RepeatedField< bool >&
      bn() const;
  inline ::google::protobuf::RepeatedField< bool >*
      mutable_bn();
  
  // repeated int32 in = 22;
  inline int in_size() const;
  inline void clear_in();
  static const int kInFieldNumber = 22;
  inline ::google::protobuf::int32 in(int index) const;
  inline void set_in(int index, ::google::protobuf::int32 value);
  inline void add_in(::google::protobuf::int32 value);
  inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
      in() const;
  inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
      mutable_in();
  
  // repeated float fn = 23;
  inline int fn_size() const;
  inline void clear_fn();
  static const int kFnFieldNumber = 23;
  inline float fn(int index) const;
  inline void set_fn(int index, float value);
  inline void add_fn(float value);
  inline const ::google::protobuf::RepeatedField< float >&
      fn() const;
  inline ::google::protobuf::RepeatedField< float >*
      mutable_fn();
  
  // repeated .google.protobuf.xml.PbValueType en = 24;
  inline int en_size() const;
  inline void clear_en();
  static const int kEnFieldNumber = 24;
  inline google::protobuf::xml::PbValueType en(int index) const;
  inline void set_en(int index, google::protobuf::xml::PbValueType value);
  inline void add_en(google::protobuf::xml::PbValueType value);
  inline const ::google::protobuf::RepeatedField<int>& en() const;
  inline ::google::protobuf::RepeatedField<int>* mutable_en();
  
  // repeated .google.protobuf.xml.PbMessage mn = 25;
  inline int mn_size() const;
  inline void clear_mn();
  static const int kMnFieldNumber = 25;
  inline const ::google::protobuf::xml::PbMessage& mn(int index) const;
  inline ::google::protobuf::xml::PbMessage* mutable_mn(int index);
  inline ::google::protobuf::xml::PbMessage* add_mn();
  inline const ::google::protobuf::RepeatedPtrField< ::google::protobuf::xml::PbMessage >&
      mn() const;
  inline ::google::protobuf::RepeatedPtrField< ::google::protobuf::xml::PbMessage >*
      mutable_mn();
  
  // @@protoc_insertion_point(class_scope:google.protobuf.xml.PbXmlTest)
 private:
  inline void set_has_b();
  inline void clear_has_b();
  inline void set_has_i();
  inline void clear_has_i();
  inline void set_has_f();
  inline void clear_has_f();
  inline void set_has_e();
  inline void clear_has_e();
  inline void set_has_m();
  inline void clear_has_m();
  inline void set_has_b1();
  inline void clear_has_b1();
  inline void set_has_i1();
  inline void clear_has_i1();
  inline void set_has_f1();
  inline void clear_has_f1();
  inline void set_has_e1();
  inline void clear_has_e1();
  inline void set_has_m1();
  inline void clear_has_m1();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::google::protobuf::int32 i_;
  float f_;
  bool b_;
  bool b1_;
  int e_;
  ::google::protobuf::xml::PbMessage* m_;
  ::google::protobuf::int32 i1_;
  float f1_;
  ::google::protobuf::xml::PbMessage* m1_;
  ::google::protobuf::RepeatedField< bool > bn_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 > in_;
  ::google::protobuf::RepeatedField< float > fn_;
  ::google::protobuf::RepeatedField<int> en_;
  ::google::protobuf::RepeatedPtrField< ::google::protobuf::xml::PbMessage > mn_;
  int e1_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(15 + 31) / 32];
  
  friend void  protobuf_AddDesc_XmlTest_2eproto();
  friend void protobuf_AssignDesc_XmlTest_2eproto();
  friend void protobuf_ShutdownFile_XmlTest_2eproto();
  
  void InitAsDefaultInstance();
  static PbXmlTest* default_instance_;
};
// ===================================================================


// ===================================================================

// PbMessage

// required bool b = 1;
inline bool PbMessage::has_b() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void PbMessage::set_has_b() {
  _has_bits_[0] |= 0x00000001u;
}
inline void PbMessage::clear_has_b() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void PbMessage::clear_b() {
  b_ = false;
  clear_has_b();
}
inline bool PbMessage::b() const {
  return b_;
}
inline void PbMessage::set_b(bool value) {
  set_has_b();
  b_ = value;
}

// required int32 i = 2;
inline bool PbMessage::has_i() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void PbMessage::set_has_i() {
  _has_bits_[0] |= 0x00000002u;
}
inline void PbMessage::clear_has_i() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void PbMessage::clear_i() {
  i_ = 0;
  clear_has_i();
}
inline ::google::protobuf::int32 PbMessage::i() const {
  return i_;
}
inline void PbMessage::set_i(::google::protobuf::int32 value) {
  set_has_i();
  i_ = value;
}

// -------------------------------------------------------------------

// PbXmlTest

// required bool b = 1 [default = true];
inline bool PbXmlTest::has_b() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void PbXmlTest::set_has_b() {
  _has_bits_[0] |= 0x00000001u;
}
inline void PbXmlTest::clear_has_b() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void PbXmlTest::clear_b() {
  b_ = true;
  clear_has_b();
}
inline bool PbXmlTest::b() const {
  return b_;
}
inline void PbXmlTest::set_b(bool value) {
  set_has_b();
  b_ = value;
}

// required int32 i = 2 [default = 123];
inline bool PbXmlTest::has_i() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void PbXmlTest::set_has_i() {
  _has_bits_[0] |= 0x00000002u;
}
inline void PbXmlTest::clear_has_i() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void PbXmlTest::clear_i() {
  i_ = 123;
  clear_has_i();
}
inline ::google::protobuf::int32 PbXmlTest::i() const {
  return i_;
}
inline void PbXmlTest::set_i(::google::protobuf::int32 value) {
  set_has_i();
  i_ = value;
}

// required float f = 3;
inline bool PbXmlTest::has_f() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void PbXmlTest::set_has_f() {
  _has_bits_[0] |= 0x00000004u;
}
inline void PbXmlTest::clear_has_f() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void PbXmlTest::clear_f() {
  f_ = 0;
  clear_has_f();
}
inline float PbXmlTest::f() const {
  return f_;
}
inline void PbXmlTest::set_f(float value) {
  set_has_f();
  f_ = value;
}

// required .google.protobuf.xml.PbValueType e = 4 [default = PB_VALUE_TYPE_BOOL];
inline bool PbXmlTest::has_e() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void PbXmlTest::set_has_e() {
  _has_bits_[0] |= 0x00000008u;
}
inline void PbXmlTest::clear_has_e() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void PbXmlTest::clear_e() {
  e_ = 1;
  clear_has_e();
}
inline google::protobuf::xml::PbValueType PbXmlTest::e() const {
  return static_cast< google::protobuf::xml::PbValueType >(e_);
}
inline void PbXmlTest::set_e(google::protobuf::xml::PbValueType value) {
  GOOGLE_DCHECK(google::protobuf::xml::PbValueType_IsValid(value));
  set_has_e();
  e_ = value;
}

// required .google.protobuf.xml.PbMessage m = 5;
inline bool PbXmlTest::has_m() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void PbXmlTest::set_has_m() {
  _has_bits_[0] |= 0x00000010u;
}
inline void PbXmlTest::clear_has_m() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void PbXmlTest::clear_m() {
  if (m_ != NULL) m_->::google::protobuf::xml::PbMessage::Clear();
  clear_has_m();
}
inline const ::google::protobuf::xml::PbMessage& PbXmlTest::m() const {
  return m_ != NULL ? *m_ : *default_instance_->m_;
}
inline ::google::protobuf::xml::PbMessage* PbXmlTest::mutable_m() {
  set_has_m();
  if (m_ == NULL) m_ = new ::google::protobuf::xml::PbMessage;
  return m_;
}
inline ::google::protobuf::xml::PbMessage* PbXmlTest::release_m() {
  clear_has_m();
  ::google::protobuf::xml::PbMessage* temp = m_;
  m_ = NULL;
  return temp;
}

// optional bool b1 = 11 [default = true];
inline bool PbXmlTest::has_b1() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void PbXmlTest::set_has_b1() {
  _has_bits_[0] |= 0x00000020u;
}
inline void PbXmlTest::clear_has_b1() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void PbXmlTest::clear_b1() {
  b1_ = true;
  clear_has_b1();
}
inline bool PbXmlTest::b1() const {
  return b1_;
}
inline void PbXmlTest::set_b1(bool value) {
  set_has_b1();
  b1_ = value;
}

// optional int32 i1 = 12 [default = 456];
inline bool PbXmlTest::has_i1() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void PbXmlTest::set_has_i1() {
  _has_bits_[0] |= 0x00000040u;
}
inline void PbXmlTest::clear_has_i1() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void PbXmlTest::clear_i1() {
  i1_ = 456;
  clear_has_i1();
}
inline ::google::protobuf::int32 PbXmlTest::i1() const {
  return i1_;
}
inline void PbXmlTest::set_i1(::google::protobuf::int32 value) {
  set_has_i1();
  i1_ = value;
}

// optional float f1 = 13;
inline bool PbXmlTest::has_f1() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void PbXmlTest::set_has_f1() {
  _has_bits_[0] |= 0x00000080u;
}
inline void PbXmlTest::clear_has_f1() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void PbXmlTest::clear_f1() {
  f1_ = 0;
  clear_has_f1();
}
inline float PbXmlTest::f1() const {
  return f1_;
}
inline void PbXmlTest::set_f1(float value) {
  set_has_f1();
  f1_ = value;
}

// optional .google.protobuf.xml.PbValueType e1 = 14 [default = PB_VALUE_TYPE_INT];
inline bool PbXmlTest::has_e1() const {
  return (_has_bits_[0] & 0x00000100u) != 0;
}
inline void PbXmlTest::set_has_e1() {
  _has_bits_[0] |= 0x00000100u;
}
inline void PbXmlTest::clear_has_e1() {
  _has_bits_[0] &= ~0x00000100u;
}
inline void PbXmlTest::clear_e1() {
  e1_ = 2;
  clear_has_e1();
}
inline google::protobuf::xml::PbValueType PbXmlTest::e1() const {
  return static_cast< google::protobuf::xml::PbValueType >(e1_);
}
inline void PbXmlTest::set_e1(google::protobuf::xml::PbValueType value) {
  GOOGLE_DCHECK(google::protobuf::xml::PbValueType_IsValid(value));
  set_has_e1();
  e1_ = value;
}

// optional .google.protobuf.xml.PbMessage m1 = 15;
inline bool PbXmlTest::has_m1() const {
  return (_has_bits_[0] & 0x00000200u) != 0;
}
inline void PbXmlTest::set_has_m1() {
  _has_bits_[0] |= 0x00000200u;
}
inline void PbXmlTest::clear_has_m1() {
  _has_bits_[0] &= ~0x00000200u;
}
inline void PbXmlTest::clear_m1() {
  if (m1_ != NULL) m1_->::google::protobuf::xml::PbMessage::Clear();
  clear_has_m1();
}
inline const ::google::protobuf::xml::PbMessage& PbXmlTest::m1() const {
  return m1_ != NULL ? *m1_ : *default_instance_->m1_;
}
inline ::google::protobuf::xml::PbMessage* PbXmlTest::mutable_m1() {
  set_has_m1();
  if (m1_ == NULL) m1_ = new ::google::protobuf::xml::PbMessage;
  return m1_;
}
inline ::google::protobuf::xml::PbMessage* PbXmlTest::release_m1() {
  clear_has_m1();
  ::google::protobuf::xml::PbMessage* temp = m1_;
  m1_ = NULL;
  return temp;
}

// repeated bool bn = 21;
inline int PbXmlTest::bn_size() const {
  return bn_.size();
}
inline void PbXmlTest::clear_bn() {
  bn_.Clear();
}
inline bool PbXmlTest::bn(int index) const {
  return bn_.Get(index);
}
inline void PbXmlTest::set_bn(int index, bool value) {
  bn_.Set(index, value);
}
inline void PbXmlTest::add_bn(bool value) {
  bn_.Add(value);
}
inline const ::google::protobuf::RepeatedField< bool >&
PbXmlTest::bn() const {
  return bn_;
}
inline ::google::protobuf::RepeatedField< bool >*
PbXmlTest::mutable_bn() {
  return &bn_;
}

// repeated int32 in = 22;
inline int PbXmlTest::in_size() const {
  return in_.size();
}
inline void PbXmlTest::clear_in() {
  in_.Clear();
}
inline ::google::protobuf::int32 PbXmlTest::in(int index) const {
  return in_.Get(index);
}
inline void PbXmlTest::set_in(int index, ::google::protobuf::int32 value) {
  in_.Set(index, value);
}
inline void PbXmlTest::add_in(::google::protobuf::int32 value) {
  in_.Add(value);
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
PbXmlTest::in() const {
  return in_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
PbXmlTest::mutable_in() {
  return &in_;
}

// repeated float fn = 23;
inline int PbXmlTest::fn_size() const {
  return fn_.size();
}
inline void PbXmlTest::clear_fn() {
  fn_.Clear();
}
inline float PbXmlTest::fn(int index) const {
  return fn_.Get(index);
}
inline void PbXmlTest::set_fn(int index, float value) {
  fn_.Set(index, value);
}
inline void PbXmlTest::add_fn(float value) {
  fn_.Add(value);
}
inline const ::google::protobuf::RepeatedField< float >&
PbXmlTest::fn() const {
  return fn_;
}
inline ::google::protobuf::RepeatedField< float >*
PbXmlTest::mutable_fn() {
  return &fn_;
}

// repeated .google.protobuf.xml.PbValueType en = 24;
inline int PbXmlTest::en_size() const {
  return en_.size();
}
inline void PbXmlTest::clear_en() {
  en_.Clear();
}
inline google::protobuf::xml::PbValueType PbXmlTest::en(int index) const {
  return static_cast< google::protobuf::xml::PbValueType >(en_.Get(index));
}
inline void PbXmlTest::set_en(int index, google::protobuf::xml::PbValueType value) {
  GOOGLE_DCHECK(google::protobuf::xml::PbValueType_IsValid(value));
  en_.Set(index, value);
}
inline void PbXmlTest::add_en(google::protobuf::xml::PbValueType value) {
  GOOGLE_DCHECK(google::protobuf::xml::PbValueType_IsValid(value));
  en_.Add(value);
}
inline const ::google::protobuf::RepeatedField<int>&
PbXmlTest::en() const {
  return en_;
}
inline ::google::protobuf::RepeatedField<int>*
PbXmlTest::mutable_en() {
  return &en_;
}

// repeated .google.protobuf.xml.PbMessage mn = 25;
inline int PbXmlTest::mn_size() const {
  return mn_.size();
}
inline void PbXmlTest::clear_mn() {
  mn_.Clear();
}
inline const ::google::protobuf::xml::PbMessage& PbXmlTest::mn(int index) const {
  return mn_.Get(index);
}
inline ::google::protobuf::xml::PbMessage* PbXmlTest::mutable_mn(int index) {
  return mn_.Mutable(index);
}
inline ::google::protobuf::xml::PbMessage* PbXmlTest::add_mn() {
  return mn_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::google::protobuf::xml::PbMessage >&
PbXmlTest::mn() const {
  return mn_;
}
inline ::google::protobuf::RepeatedPtrField< ::google::protobuf::xml::PbMessage >*
PbXmlTest::mutable_mn() {
  return &mn_;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace xml
}  // namespace protobuf
}  // namespace google

#ifndef SWIG
namespace google {
namespace protobuf {

template <>
inline const EnumDescriptor* GetEnumDescriptor< google::protobuf::xml::PbValueType>() {
  return google::protobuf::xml::PbValueType_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_XmlTest_2eproto__INCLUDED
