// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: session.proto

#include "session.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
class SessionDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<Session> _instance;
} _Session_default_instance_;
static void InitDefaultsscc_info_Session_session_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_Session_default_instance_;
    new (ptr) ::Session();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::Session::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_Session_session_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_Session_session_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_session_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_session_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_session_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_session_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Session, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::Session, session_),
  PROTOBUF_FIELD_OFFSET(::Session, sensor_),
  PROTOBUF_FIELD_OFFSET(::Session, starttime_),
  PROTOBUF_FIELD_OFFSET(::Session, endtime_),
  PROTOBUF_FIELD_OFFSET(::Session, value_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::Session)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_Session_default_instance_),
};

const char descriptor_table_protodef_session_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\rsession.proto\"]\n\007Session\022\017\n\007session\030\001 "
  "\001(\t\022\016\n\006sensor\030\002 \001(\t\022\021\n\tstartTime\030\003 \001(\003\022\017"
  "\n\007endTime\030\004 \001(\003\022\r\n\005value\030\005 \003(\002b\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_session_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_session_2eproto_sccs[1] = {
  &scc_info_Session_session_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_session_2eproto_once;
static bool descriptor_table_session_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_session_2eproto = {
  &descriptor_table_session_2eproto_initialized, descriptor_table_protodef_session_2eproto, "session.proto", 118,
  &descriptor_table_session_2eproto_once, descriptor_table_session_2eproto_sccs, descriptor_table_session_2eproto_deps, 1, 0,
  schemas, file_default_instances, TableStruct_session_2eproto::offsets,
  file_level_metadata_session_2eproto, 1, file_level_enum_descriptors_session_2eproto, file_level_service_descriptors_session_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_session_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_session_2eproto), true);

// ===================================================================

void Session::InitAsDefaultInstance() {
}
class Session::_Internal {
 public:
};

Session::Session()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:Session)
}
Session::Session(const Session& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      value_(from.value_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  session_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_session().empty()) {
    session_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.session_);
  }
  sensor_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_sensor().empty()) {
    sensor_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.sensor_);
  }
  ::memcpy(&starttime_, &from.starttime_,
    static_cast<size_t>(reinterpret_cast<char*>(&endtime_) -
    reinterpret_cast<char*>(&starttime_)) + sizeof(endtime_));
  // @@protoc_insertion_point(copy_constructor:Session)
}

void Session::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_Session_session_2eproto.base);
  session_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  sensor_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::memset(&starttime_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&endtime_) -
      reinterpret_cast<char*>(&starttime_)) + sizeof(endtime_));
}

Session::~Session() {
  // @@protoc_insertion_point(destructor:Session)
  SharedDtor();
}

void Session::SharedDtor() {
  session_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  sensor_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void Session::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const Session& Session::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_Session_session_2eproto.base);
  return *internal_default_instance();
}


void Session::Clear() {
// @@protoc_insertion_point(message_clear_start:Session)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  value_.Clear();
  session_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  sensor_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::memset(&starttime_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&endtime_) -
      reinterpret_cast<char*>(&starttime_)) + sizeof(endtime_));
  _internal_metadata_.Clear();
}

const char* Session::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string session = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_session();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "Session.session"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string sensor = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_sensor();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "Session.sensor"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // int64 startTime = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          starttime_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // int64 endTime = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 32)) {
          endtime_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // repeated float value = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 42)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::PackedFloatParser(_internal_mutable_value(), ptr, ctx);
          CHK_(ptr);
        } else if (static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 45) {
          _internal_add_value(::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr));
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* Session::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Session)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string session = 1;
  if (this->session().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_session().data(), static_cast<int>(this->_internal_session().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Session.session");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_session(), target);
  }

  // string sensor = 2;
  if (this->sensor().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_sensor().data(), static_cast<int>(this->_internal_sensor().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Session.sensor");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_sensor(), target);
  }

  // int64 startTime = 3;
  if (this->starttime() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt64ToArray(3, this->_internal_starttime(), target);
  }

  // int64 endTime = 4;
  if (this->endtime() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt64ToArray(4, this->_internal_endtime(), target);
  }

  // repeated float value = 5;
  if (this->_internal_value_size() > 0) {
    target = stream->WriteFixedPacked(5, _internal_value(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Session)
  return target;
}

size_t Session::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Session)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated float value = 5;
  {
    unsigned int count = static_cast<unsigned int>(this->_internal_value_size());
    size_t data_size = 4UL * count;
    if (data_size > 0) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
            static_cast<::PROTOBUF_NAMESPACE_ID::int32>(data_size));
    }
    int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(data_size);
    _value_cached_byte_size_.store(cached_size,
                                    std::memory_order_relaxed);
    total_size += data_size;
  }

  // string session = 1;
  if (this->session().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_session());
  }

  // string sensor = 2;
  if (this->sensor().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_sensor());
  }

  // int64 startTime = 3;
  if (this->starttime() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int64Size(
        this->_internal_starttime());
  }

  // int64 endTime = 4;
  if (this->endtime() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int64Size(
        this->_internal_endtime());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Session::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:Session)
  GOOGLE_DCHECK_NE(&from, this);
  const Session* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<Session>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:Session)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:Session)
    MergeFrom(*source);
  }
}

void Session::MergeFrom(const Session& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Session)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  value_.MergeFrom(from.value_);
  if (from.session().size() > 0) {

    session_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.session_);
  }
  if (from.sensor().size() > 0) {

    sensor_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.sensor_);
  }
  if (from.starttime() != 0) {
    _internal_set_starttime(from._internal_starttime());
  }
  if (from.endtime() != 0) {
    _internal_set_endtime(from._internal_endtime());
  }
}

void Session::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:Session)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Session::CopyFrom(const Session& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Session)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Session::IsInitialized() const {
  return true;
}

void Session::InternalSwap(Session* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  value_.InternalSwap(&other->value_);
  session_.Swap(&other->session_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  sensor_.Swap(&other->sensor_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(starttime_, other->starttime_);
  swap(endtime_, other->endtime_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Session::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::Session* Arena::CreateMaybeMessage< ::Session >(Arena* arena) {
  return Arena::CreateInternal< ::Session >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
