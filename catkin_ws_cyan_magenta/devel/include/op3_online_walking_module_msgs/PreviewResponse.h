// Generated by gencpp from file op3_online_walking_module_msgs/PreviewResponse.msg
// DO NOT EDIT!


#ifndef OP3_ONLINE_WALKING_MODULE_MSGS_MESSAGE_PREVIEWRESPONSE_H
#define OP3_ONLINE_WALKING_MODULE_MSGS_MESSAGE_PREVIEWRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace op3_online_walking_module_msgs
{
template <class ContainerAllocator>
struct PreviewResponse_
{
  typedef PreviewResponse_<ContainerAllocator> Type;

  PreviewResponse_()
    : K_row(0)
    , K_col(0)
    , K()
    , P_row(0)
    , P_col(0)
    , P()  {
    }
  PreviewResponse_(const ContainerAllocator& _alloc)
    : K_row(0)
    , K_col(0)
    , K(_alloc)
    , P_row(0)
    , P_col(0)
    , P(_alloc)  {
  (void)_alloc;
    }



   typedef int32_t _K_row_type;
  _K_row_type K_row;

   typedef int32_t _K_col_type;
  _K_col_type K_col;

   typedef std::vector<double, typename ContainerAllocator::template rebind<double>::other >  _K_type;
  _K_type K;

   typedef int32_t _P_row_type;
  _P_row_type P_row;

   typedef int32_t _P_col_type;
  _P_col_type P_col;

   typedef std::vector<double, typename ContainerAllocator::template rebind<double>::other >  _P_type;
  _P_type P;





  typedef boost::shared_ptr< ::op3_online_walking_module_msgs::PreviewResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::op3_online_walking_module_msgs::PreviewResponse_<ContainerAllocator> const> ConstPtr;

}; // struct PreviewResponse_

typedef ::op3_online_walking_module_msgs::PreviewResponse_<std::allocator<void> > PreviewResponse;

typedef boost::shared_ptr< ::op3_online_walking_module_msgs::PreviewResponse > PreviewResponsePtr;
typedef boost::shared_ptr< ::op3_online_walking_module_msgs::PreviewResponse const> PreviewResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::op3_online_walking_module_msgs::PreviewResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::op3_online_walking_module_msgs::PreviewResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace op3_online_walking_module_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'op3_online_walking_module_msgs': ['/home/robotis/catkin_ws/src/ROBOTIS-OP3-msgs/op3_online_walking_module_msgs/msg'], 'sensor_msgs': ['/opt/ros/kinetic/share/sensor_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::op3_online_walking_module_msgs::PreviewResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::op3_online_walking_module_msgs::PreviewResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::op3_online_walking_module_msgs::PreviewResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::op3_online_walking_module_msgs::PreviewResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::op3_online_walking_module_msgs::PreviewResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::op3_online_walking_module_msgs::PreviewResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::op3_online_walking_module_msgs::PreviewResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "485c4c72e8d24c7f7a770f8a88709eb6";
  }

  static const char* value(const ::op3_online_walking_module_msgs::PreviewResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x485c4c72e8d24c7fULL;
  static const uint64_t static_value2 = 0x7a770f8a88709eb6ULL;
};

template<class ContainerAllocator>
struct DataType< ::op3_online_walking_module_msgs::PreviewResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "op3_online_walking_module_msgs/PreviewResponse";
  }

  static const char* value(const ::op3_online_walking_module_msgs::PreviewResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::op3_online_walking_module_msgs::PreviewResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 K_row\n\
int32 K_col\n\
float64[] K\n\
int32 P_row\n\
int32 P_col\n\
float64[] P\n\
";
  }

  static const char* value(const ::op3_online_walking_module_msgs::PreviewResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::op3_online_walking_module_msgs::PreviewResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.K_row);
      stream.next(m.K_col);
      stream.next(m.K);
      stream.next(m.P_row);
      stream.next(m.P_col);
      stream.next(m.P);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct PreviewResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::op3_online_walking_module_msgs::PreviewResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::op3_online_walking_module_msgs::PreviewResponse_<ContainerAllocator>& v)
  {
    s << indent << "K_row: ";
    Printer<int32_t>::stream(s, indent + "  ", v.K_row);
    s << indent << "K_col: ";
    Printer<int32_t>::stream(s, indent + "  ", v.K_col);
    s << indent << "K[]" << std::endl;
    for (size_t i = 0; i < v.K.size(); ++i)
    {
      s << indent << "  K[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.K[i]);
    }
    s << indent << "P_row: ";
    Printer<int32_t>::stream(s, indent + "  ", v.P_row);
    s << indent << "P_col: ";
    Printer<int32_t>::stream(s, indent + "  ", v.P_col);
    s << indent << "P[]" << std::endl;
    for (size_t i = 0; i < v.P.size(); ++i)
    {
      s << indent << "  P[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.P[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // OP3_ONLINE_WALKING_MODULE_MSGS_MESSAGE_PREVIEWRESPONSE_H
