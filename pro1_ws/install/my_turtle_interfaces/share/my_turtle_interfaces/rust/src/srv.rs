#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to my_turtle_interfaces__srv__NavigateTo_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::NavigateTo_Request::default())
  }
}

impl rosidl_runtime_rs::Message for NavigateTo_Request {
  type RmwMsg = super::srv::rmw::NavigateTo_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        x: msg.x,
        y: msg.y,
        theta: msg.theta,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      x: msg.x,
      y: msg.y,
      theta: msg.theta,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      x: msg.x,
      y: msg.y,
      theta: msg.theta,
    }
  }
}


// Corresponds to my_turtle_interfaces__srv__NavigateTo_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct NavigateTo_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for NavigateTo_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::NavigateTo_Response::default())
  }
}

impl rosidl_runtime_rs::Message for NavigateTo_Response {
  type RmwMsg = super::srv::rmw::NavigateTo_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
    }
  }
}


// Corresponds to my_turtle_interfaces__srv__TeleportTo_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::TeleportTo_Request::default())
  }
}

impl rosidl_runtime_rs::Message for TeleportTo_Request {
  type RmwMsg = super::srv::rmw::TeleportTo_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        x: msg.x,
        y: msg.y,
        theta: msg.theta,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      x: msg.x,
      y: msg.y,
      theta: msg.theta,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      x: msg.x,
      y: msg.y,
      theta: msg.theta,
    }
  }
}


// Corresponds to my_turtle_interfaces__srv__TeleportTo_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TeleportTo_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for TeleportTo_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::TeleportTo_Response::default())
  }
}

impl rosidl_runtime_rs::Message for TeleportTo_Response {
  type RmwMsg = super::srv::rmw::TeleportTo_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
    }
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


