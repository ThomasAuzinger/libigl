#include "read_eigen_from_CSV.h"

#include <sstream>
#include <string>
#include <fstream>

#include <vector>

namespace igl
{

  template <typename DerivedV, typename DerivedF>
  double avg_edge_length(
    const Eigen::PlainObjectBase<DerivedV>& V,
    const Eigen::PlainObjectBase<DerivedF>& F)
  {
    double avg = 0;
    long int count = 0;

    for (unsigned i=0;i<F.rows();++i)
    {
      for (unsigned j=0;j<3;++j)
      {
        ++count;
        avg += (V.row(F(i,j)) - V.row(F(i,(j+1)%3))).norm();
      }
    }

    return avg / (double) count;
  }

}

#ifndef IGL_HEADER_ONLY
// Explicit template specialization
// generated by autoexplicit.sh
#endif
