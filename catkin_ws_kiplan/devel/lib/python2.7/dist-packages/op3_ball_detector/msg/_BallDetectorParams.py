# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from op3_ball_detector/BallDetectorParams.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class BallDetectorParams(genpy.Message):
  _md5sum = "23a4c471d4f161f32a80066aac78a96c"
  _type = "op3_ball_detector/BallDetectorParams"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """# This represents the parameters of ball_detector

uint32  gaussian_blur_size      # only odd number, 1 - 11
float32 gaussian_blur_sigma     # 1 - 5
float32 canny_edge_th           # 50 - 200
float32 hough_accum_resolution  # 1 - 8
float32 hough_accum_th          # 10 - 200
float32 min_circle_dist         # 10 - 200
uint32  min_radius              # 10 - 200
uint32  max_radius              # 100 - 600
uint32  filter_h_min            # 0 - 359
uint32  filter_h_max
uint32  filter_s_min            # 0 - 255
uint32  filter_s_max
uint32  filter_v_min            # 0 - 255
uint32  filter_v_max
uint32  ellipse_size            # 1 - 9
"""
  __slots__ = ['gaussian_blur_size','gaussian_blur_sigma','canny_edge_th','hough_accum_resolution','hough_accum_th','min_circle_dist','min_radius','max_radius','filter_h_min','filter_h_max','filter_s_min','filter_s_max','filter_v_min','filter_v_max','ellipse_size']
  _slot_types = ['uint32','float32','float32','float32','float32','float32','uint32','uint32','uint32','uint32','uint32','uint32','uint32','uint32','uint32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       gaussian_blur_size,gaussian_blur_sigma,canny_edge_th,hough_accum_resolution,hough_accum_th,min_circle_dist,min_radius,max_radius,filter_h_min,filter_h_max,filter_s_min,filter_s_max,filter_v_min,filter_v_max,ellipse_size

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(BallDetectorParams, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.gaussian_blur_size is None:
        self.gaussian_blur_size = 0
      if self.gaussian_blur_sigma is None:
        self.gaussian_blur_sigma = 0.
      if self.canny_edge_th is None:
        self.canny_edge_th = 0.
      if self.hough_accum_resolution is None:
        self.hough_accum_resolution = 0.
      if self.hough_accum_th is None:
        self.hough_accum_th = 0.
      if self.min_circle_dist is None:
        self.min_circle_dist = 0.
      if self.min_radius is None:
        self.min_radius = 0
      if self.max_radius is None:
        self.max_radius = 0
      if self.filter_h_min is None:
        self.filter_h_min = 0
      if self.filter_h_max is None:
        self.filter_h_max = 0
      if self.filter_s_min is None:
        self.filter_s_min = 0
      if self.filter_s_max is None:
        self.filter_s_max = 0
      if self.filter_v_min is None:
        self.filter_v_min = 0
      if self.filter_v_max is None:
        self.filter_v_max = 0
      if self.ellipse_size is None:
        self.ellipse_size = 0
    else:
      self.gaussian_blur_size = 0
      self.gaussian_blur_sigma = 0.
      self.canny_edge_th = 0.
      self.hough_accum_resolution = 0.
      self.hough_accum_th = 0.
      self.min_circle_dist = 0.
      self.min_radius = 0
      self.max_radius = 0
      self.filter_h_min = 0
      self.filter_h_max = 0
      self.filter_s_min = 0
      self.filter_s_max = 0
      self.filter_v_min = 0
      self.filter_v_max = 0
      self.ellipse_size = 0

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_I5f9I().pack(_x.gaussian_blur_size, _x.gaussian_blur_sigma, _x.canny_edge_th, _x.hough_accum_resolution, _x.hough_accum_th, _x.min_circle_dist, _x.min_radius, _x.max_radius, _x.filter_h_min, _x.filter_h_max, _x.filter_s_min, _x.filter_s_max, _x.filter_v_min, _x.filter_v_max, _x.ellipse_size))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      _x = self
      start = end
      end += 60
      (_x.gaussian_blur_size, _x.gaussian_blur_sigma, _x.canny_edge_th, _x.hough_accum_resolution, _x.hough_accum_th, _x.min_circle_dist, _x.min_radius, _x.max_radius, _x.filter_h_min, _x.filter_h_max, _x.filter_s_min, _x.filter_s_max, _x.filter_v_min, _x.filter_v_max, _x.ellipse_size,) = _get_struct_I5f9I().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_I5f9I().pack(_x.gaussian_blur_size, _x.gaussian_blur_sigma, _x.canny_edge_th, _x.hough_accum_resolution, _x.hough_accum_th, _x.min_circle_dist, _x.min_radius, _x.max_radius, _x.filter_h_min, _x.filter_h_max, _x.filter_s_min, _x.filter_s_max, _x.filter_v_min, _x.filter_v_max, _x.ellipse_size))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      _x = self
      start = end
      end += 60
      (_x.gaussian_blur_size, _x.gaussian_blur_sigma, _x.canny_edge_th, _x.hough_accum_resolution, _x.hough_accum_th, _x.min_circle_dist, _x.min_radius, _x.max_radius, _x.filter_h_min, _x.filter_h_max, _x.filter_s_min, _x.filter_s_max, _x.filter_v_min, _x.filter_v_max, _x.ellipse_size,) = _get_struct_I5f9I().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_I5f9I = None
def _get_struct_I5f9I():
    global _struct_I5f9I
    if _struct_I5f9I is None:
        _struct_I5f9I = struct.Struct("<I5f9I")
    return _struct_I5f9I
