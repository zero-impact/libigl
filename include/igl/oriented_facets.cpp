// This file is part of libigl, a simple c++ geometry processing library.
// 
// Copyright (C) 2017 Alec Jacobson <alecjacobson@gmail.com>
// 
// This Source Code Form is subject to the terms of the Mozilla Public License 
// v. 2.0. If a copy of the MPL was not distributed with this file, You can 
// obtain one at http://mozilla.org/MPL/2.0/.
#include "oriented_facets.h"

template <typename DerivedF, typename DerivedE>
IGL_INLINE void igl::oriented_facets(
  const Eigen::MatrixBase<DerivedF> & F,
  Eigen::PlainObjectBase<DerivedE> & E)
{
  E.resize(F.rows()*F.cols(),F.cols()-1);
  typedef typename DerivedE::Scalar EScalar;
  switch(F.cols())
  {
    case 4:
      E.block(0*F.rows(),0,F.rows(),1) = F.col(1).template cast<EScalar>();
      E.block(0*F.rows(),1,F.rows(),1) = F.col(3).template cast<EScalar>();
      E.block(0*F.rows(),2,F.rows(),1) = F.col(2).template cast<EScalar>();

      E.block(1*F.rows(),0,F.rows(),1) = F.col(0).template cast<EScalar>();
      E.block(1*F.rows(),1,F.rows(),1) = F.col(2).template cast<EScalar>();
      E.block(1*F.rows(),2,F.rows(),1) = F.col(3).template cast<EScalar>();

      E.block(2*F.rows(),0,F.rows(),1) = F.col(0).template cast<EScalar>();
      E.block(2*F.rows(),1,F.rows(),1) = F.col(3).template cast<EScalar>();
      E.block(2*F.rows(),2,F.rows(),1) = F.col(1).template cast<EScalar>();

      E.block(3*F.rows(),0,F.rows(),1) = F.col(0).template cast<EScalar>();
      E.block(3*F.rows(),1,F.rows(),1) = F.col(1).template cast<EScalar>();
      E.block(3*F.rows(),2,F.rows(),1) = F.col(2).template cast<EScalar>();
      return;
    case 3:
      E.block(0*F.rows(),0,F.rows(),1) = F.col(1).template cast<EScalar>();
      E.block(0*F.rows(),1,F.rows(),1) = F.col(2).template cast<EScalar>();
      E.block(1*F.rows(),0,F.rows(),1) = F.col(2).template cast<EScalar>();
      E.block(1*F.rows(),1,F.rows(),1) = F.col(0).template cast<EScalar>();
      E.block(2*F.rows(),0,F.rows(),1) = F.col(0).template cast<EScalar>();
      E.block(2*F.rows(),1,F.rows(),1) = F.col(1).template cast<EScalar>();
      return;
  }
}

#ifdef IGL_STATIC_LIBRARY
// Explicit template instantiation
template void igl::oriented_facets<Eigen::Matrix<int, -1, -1, 0, -1, -1>, Eigen::Matrix<int, -1, -1, 0, -1, -1> >(Eigen::MatrixBase<Eigen::Matrix<int, -1, -1, 0, -1, -1> > const&, Eigen::PlainObjectBase<Eigen::Matrix<int, -1, -1, 0, -1, -1> >&);
template void igl::oriented_facets<Eigen::Matrix<int, -1, 3, 0, -1, 3>, Eigen::Matrix<int, -1, 2, 0, -1, 2> >(Eigen::MatrixBase<Eigen::Matrix<int, -1, 3, 0, -1, 3> > const&, Eigen::PlainObjectBase<Eigen::Matrix<int, -1, 2, 0, -1, 2> >&);
template void igl::oriented_facets<Eigen::Matrix<int, -1, -1, 0, -1, -1>, Eigen::Matrix<int, -1, 2, 0, -1, 2> >(Eigen::MatrixBase<Eigen::Matrix<int, -1, -1, 0, -1, -1> > const&, Eigen::PlainObjectBase<Eigen::Matrix<int, -1, 2, 0, -1, 2> >&);
template void igl::oriented_facets<Eigen::Matrix<int, -1, 3, 0, -1, 3>, Eigen::Matrix<int, -1, -1, 0, -1, -1> >(Eigen::MatrixBase<Eigen::Matrix<int, -1, 3, 0, -1, 3> > const&, Eigen::PlainObjectBase<Eigen::Matrix<int, -1, -1, 0, -1, -1> >&);
template void igl::oriented_facets<Eigen::Matrix<double, -1, -1, 0, -1, -1>, Eigen::Matrix<double, -1, 2, 0, -1, 2> >(Eigen::MatrixBase<Eigen::Matrix<double, -1, -1, 0, -1, -1> > const&, Eigen::PlainObjectBase<Eigen::Matrix<double, -1, 2, 0, -1, 2> >&);
#endif

