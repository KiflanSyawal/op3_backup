// Generated by gencpp from file utils/GetVisionDev.msg
// DO NOT EDIT!


#ifndef UTILS_MESSAGE_GETVISIONDEV_H
#define UTILS_MESSAGE_GETVISIONDEV_H

#include <ros/service_traits.h>


#include <utils/GetVisionDevRequest.h>
#include <utils/GetVisionDevResponse.h>


namespace utils
{

struct GetVisionDev
{

typedef GetVisionDevRequest Request;
typedef GetVisionDevResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct GetVisionDev
} // namespace utils


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::utils::GetVisionDev > {
  static const char* value()
  {
    return "28d20ec34b723ab37e9c2029519bbce4";
  }

  static const char* value(const ::utils::GetVisionDev&) { return value(); }
};

template<>
struct DataType< ::utils::GetVisionDev > {
  static const char* value()
  {
    return "utils/GetVisionDev";
  }

  static const char* value(const ::utils::GetVisionDev&) { return value(); }
};


// service_traits::MD5Sum< ::utils::GetVisionDevRequest> should match 
// service_traits::MD5Sum< ::utils::GetVisionDev > 
template<>
struct MD5Sum< ::utils::GetVisionDevRequest>
{
  static const char* value()
  {
    return MD5Sum< ::utils::GetVisionDev >::value();
  }
  static const char* value(const ::utils::GetVisionDevRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::utils::GetVisionDevRequest> should match 
// service_traits::DataType< ::utils::GetVisionDev > 
template<>
struct DataType< ::utils::GetVisionDevRequest>
{
  static const char* value()
  {
    return DataType< ::utils::GetVisionDev >::value();
  }
  static const char* value(const ::utils::GetVisionDevRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::utils::GetVisionDevResponse> should match 
// service_traits::MD5Sum< ::utils::GetVisionDev > 
template<>
struct MD5Sum< ::utils::GetVisionDevResponse>
{
  static const char* value()
  {
    return MD5Sum< ::utils::GetVisionDev >::value();
  }
  static const char* value(const ::utils::GetVisionDevResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::utils::GetVisionDevResponse> should match 
// service_traits::DataType< ::utils::GetVisionDev > 
template<>
struct DataType< ::utils::GetVisionDevResponse>
{
  static const char* value()
  {
    return DataType< ::utils::GetVisionDev >::value();
  }
  static const char* value(const ::utils::GetVisionDevResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // UTILS_MESSAGE_GETVISIONDEV_H