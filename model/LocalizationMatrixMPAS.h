/*
 * (C) Copyright 2017 UCAR
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 */

#ifndef MODEL_LOCALIZATIONMATRIXMPAS_H_
#define MODEL_LOCALIZATIONMATRIXMPAS_H_

#include <ostream>
#include <string>
#include <boost/noncopyable.hpp>
#include <boost/scoped_ptr.hpp>

#include "GeometryMPAS.h"
#include "eckit/config/Configuration.h"
#include "oops/interface/LocalizationBase.h"
#include "oops/util/DateTime.h"
#include "oops/util/ObjectCounter.h"
#include "oops/util/Printable.h"

#include "Fortran.h"

// Forward declarations
namespace mpas {
  class GeometryMPAS;
  class IncrementMPAS;

/// Localization matrix for MPAS model.

// -----------------------------------------------------------------------------
class LocalizationMatrixMPAS: public util::Printable,
                           private boost::noncopyable,
                           private util::ObjectCounter<LocalizationMatrixMPAS> {
 public:
  static const std::string classname() {return "mpas::LocalizationMatrixMPAS";}

  LocalizationMatrixMPAS(const GeometryMPAS &, const eckit::Configuration &);
  ~LocalizationMatrixMPAS();
  void multiply(IncrementMPAS &) const;

 private:
  void print(std::ostream &) const;
  F90lclz keyFtnConfig_;
};
// -----------------------------------------------------------------------------

}  // namespace mpas

#endif  // MODEL_LOCALIZATIONMATRIXMPAS_H_
