/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkFilterImageGaussianFirstDerivative.txx
  Language:  C++
  Date:      $Date$
  Version:   $Revision$


  Copyright (c) 2000 National Library of Medicine
  All rights reserved.

  See COPYRIGHT.txt for copyright details.

=========================================================================*/
#include "itkFilterImageGaussianFirstDerivative.h"

namespace itk
{

/**
 * Compute filter for Gaussian kernel
 */
template <class TInputImage, class TOutputImage, class TComputation>
void
FilterImageGaussianFirstDerivative<TInputImage,TOutputImage, TComputation>
::SetUp(TComputation dd)
{
  a0 = TComputation( -0.6472 );
  a1 = TComputation( -4.5310 );
  b0 = TComputation(  1.5270 );
  b1 = TComputation(  1.5160 );
  c0 = TComputation(  0.6494 );
  c1 = TComputation(  0.9557 );
  w0 = TComputation(  0.6719 );
  w1 = TComputation(  2.0720 );

  const TComputation sigmad = cSigma/dd;
//K = 1.0/(sigmad*sigmad*sqrt(2.0*(4.0*atan(1.0))));
  K = 1.0 / ( sigmad * sqrt( 2.0 * ( 4.0 * atan( 1.0 ) ) ) );

  const bool symmetric = false;
  ComputeFilterCoefficients(symmetric);
}

} // end namespace itk
