#ifndef IGL_DUAL_MESH_LIST_H
#define IGL_DUAL_MESH_LIST_H
#include "igl_inline.h"

#include <Eigen/Dense>

namespace igl 
{
  // Refine the mesh by adding the barycenter of each face
  // Inputs:
  //   V       #V by 3 coordinates of the vertices
  //   F       #F by 3 list of mesh faces (must be triangles)
  // Outputs: 
  //   VD      #V + #F by 3 coordinate of the vertices of the dual mesh
  //           The added vertices are added at the end of VD
  //   FD      #F*3 by 3 faces of the dual mesh
  //
  template <typename Scalar, typename Index>
  IGL_INLINE void add_barycenter(
    const Eigen::PlainObjectBase<Scalar> & V, 
    const Eigen::PlainObjectBase<Index> & F, 
    Eigen::PlainObjectBase<Scalar> & VD, 
    Eigen::PlainObjectBase<Index> & FD);

}

#ifdef IGL_HEADER_ONLY
#  include "add_barycenter.cpp"
#endif

#endif
