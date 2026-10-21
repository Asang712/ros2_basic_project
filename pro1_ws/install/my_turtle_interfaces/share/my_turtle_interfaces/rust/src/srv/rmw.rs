#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "my_turtle_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__my_turtle_interfaces__srv__NavigateTo_Request() -> *const std::ffi::c_void;
}

#[link(name = "my_turtle_interfaces__rosidl_generator_c")]
extern "C" {
    fn my_turtle_interfaces__srv__NavigateTo_Request__init(msg: *mut NavigateTo_Request) -> bool;
    fn my_turtle_interfaces__srv__NavigateTo_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<NavigateTo_Request>, size: usize) -> bool;
    fn my_turtle_interfaces__srv__NavigateTo_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<NavigateTo_Request>);
    fn my_turtle_interfaces__srv__NavigateTo_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<NavigateTo_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<NavigateTo_Request>) -> bool;
}

// Corresponds to my_turtle_interfaces__srv__NavigateTo_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct NavigateTo_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub x: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub y: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub theta: f32,

}



impl Default for NavigateTo_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !my_turtle_interfaces__srv__NavigateTo_Request__init(&mut msg as *mut _) {
        panic!("Call to my_turtle_interfaces__srv__NavigateTo_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for NavigateTo_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { my_turtle_interfaces__srv__NavigateTo_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { my_turtle_interfaces__srv__NavigateTo_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { my_turtle_interfaces__srv__NavigateTo_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for NavigateTo_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for NavigateTo_Request where Self: Sized {
  const TYPE_NAME: &'static str = "my_turtle_interfaces/srv/NavigateTo_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__my_turtle_interfaces__srv__NavigateTo_Request() }
  }
}


#[link(name = "my_turtle_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__my_turtle_interfaces__srv__NavigateTo_Response() -> *const std::ffi::c_void;
}

#[link(name = "my_turtle_interfaces__rosidl_generator_c")]
extern "C" {
    fn my_turtle_interfaces__srv__NavigateTo_Response__init(msg: *mut NavigateTo_Response) -> bool;
    fn my_turtle_interfaces__srv__NavigateTo_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<NavigateTo_Response>, size: usize) -> bool;
    fn my_turtle_interfaces__srv__NavigateTo_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<NavigateTo_Response>);
    fn my_turtle_interfaces__srv__NavigateTo_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<NavigateTo_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<NavigateTo_Response>) -> bool;
}

// Corresponds to my_turtle_interfaces__srv__NavigateTo_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct NavigateTo_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for NavigateTo_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !my_turtle_interfaces__srv__NavigateTo_Response__init(&mut msg as *mut _) {
        panic!("Call to my_turtle_interfaces__srv__NavigateTo_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for NavigateTo_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { my_turtle_interfaces__srv__NavigateTo_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { my_turtle_interfaces__srv__NavigateTo_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { my_turtle_interfaces__srv__NavigateTo_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for NavigateTo_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for NavigateTo_Response where Self: Sized {
  const TYPE_NAME: &'static str = "my_turtle_interfaces/srv/NavigateTo_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__my_turtle_interfaces__srv__NavigateTo_Response() }
  }
}


#[link(name = "my_turtle_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__my_turtle_interfaces__srv__TeleportTo_Request() -> *const std::ffi::c_void;
}

#[link(name = "my_turtle_interfaces__rosidl_generator_c")]
extern "C" {
    fn my_turtle_interfaces__srv__TeleportTo_Request__init(msg: *mut TeleportTo_Request) -> bool;
    fn my_turtle_interfaces__srv__TeleportTo_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<TeleportTo_Request>, size: usize) -> bool;
    fn my_turtle_interfaces__srv__TeleportTo_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<TeleportTo_Request>);
    fn my_turtle_interfaces__srv__TeleportTo_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<TeleportTo_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<TeleportTo_Request>) -> bool;
}

// Corresponds to my_turtle_interfaces__srv__TeleportTo_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TeleportTo_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub x: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub y: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub theta: f32,

}



impl Default for TeleportTo_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !my_turtle_interfaces__srv__TeleportTo_Request__init(&mut msg as *mut _) {
        panic!("Call to my_turtle_interfaces__srv__TeleportTo_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for TeleportTo_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { my_turtle_interfaces__srv__TeleportTo_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { my_turtle_interfaces__srv__TeleportTo_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { my_turtle_interfaces__srv__TeleportTo_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for TeleportTo_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for TeleportTo_Request where Self: Sized {
  const TYPE_NAME: &'static str = "my_turtle_interfaces/srv/TeleportTo_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__my_turtle_interfaces__srv__TeleportTo_Request() }
  }
}


#[link(name = "my_turtle_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__my_turtle_interfaces__srv__TeleportTo_Response() -> *const std::ffi::c_void;
}

#[link(name = "my_turtle_interfaces__rosidl_generator_c")]
extern "C" {
    fn my_turtle_interfaces__srv__TeleportTo_Response__init(msg: *mut TeleportTo_Response) -> bool;
    fn my_turtle_interfaces__srv__TeleportTo_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<TeleportTo_Response>, size: usize) -> bool;
    fn my_turtle_interfaces__srv__TeleportTo_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<TeleportTo_Response>);
    fn my_turtle_interfaces__srv__TeleportTo_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<TeleportTo_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<TeleportTo_Response>) -> bool;
}

// Corresponds to my_turtle_interfaces__srv__TeleportTo_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TeleportTo_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for TeleportTo_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !my_turtle_interfaces__srv__TeleportTo_Response__init(&mut msg as *mut _) {
        panic!("Call to my_turtle_interfaces__srv__TeleportTo_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for TeleportTo_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { my_turtle_interfaces__srv__TeleportTo_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { my_turtle_interfaces__srv__TeleportTo_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { my_turtle_interfaces__srv__TeleportTo_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for TeleportTo_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for TeleportTo_Response where Self: Sized {
  const TYPE_NAME: &'static str = "my_turtle_interfaces/srv/TeleportTo_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__my_turtle_interfaces__srv__TeleportTo_Response() }
  }
}






#[link(name = "my_turtle_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__my_turtle_interfaces__srv__NavigateTo() -> *const std::ffi::c_void;
}

// Corresponds to my_turtle_interfaces__srv__NavigateTo
#[allow(missing_docs, non_camel_case_types)]
pub struct NavigateTo;

impl rosidl_runtime_rs::Service for NavigateTo {
    type Request = NavigateTo_Request;
    type Response = NavigateTo_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__my_turtle_interfaces__srv__NavigateTo() }
    }
}




#[link(name = "my_turtle_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__my_turtle_interfaces__srv__TeleportTo() -> *const std::ffi::c_void;
}

// Corresponds to my_turtle_interfaces__srv__TeleportTo
#[allow(missing_docs, non_camel_case_types)]
pub struct TeleportTo;

impl rosidl_runtime_rs::Service for TeleportTo {
    type Request = TeleportTo_Request;
    type Response = TeleportTo_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__my_turtle_interfaces__srv__TeleportTo() }
    }
}


