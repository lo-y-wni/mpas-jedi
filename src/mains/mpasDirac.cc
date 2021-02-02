/*
 * (C) Copyright 2009-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

#include <oops/generic/instantiateVariableChangeFactory.h>
#include <oops/runs/Dirac.h>

#include <saber/oops/instantiateCovarFactory.h>
#include <saber/oops/instantiateLocalizationFactory.h>
#include <saber/oops/instantiateVariableChangeFactory.h>

#include "mpasjedi/instantiateMPASVarChangeFactory.h"
#include "mpasjedi/MPASTraits.h"
#include "mpasjedi/RunMPAS.h"

int main(int argc,  char ** argv) {
  mpas::RunMPAS run(argc, argv);
  mpas::instantiateMPASVarChangeFactory();
  saber::instantiateCovarFactory<mpas::MPASTraits>();
  saber::instantiateLocalizationFactory<mpas::MPASTraits>();
  saber::instantiateVariableChangeFactory<mpas::MPASTraits>();
  oops::Dirac<mpas::MPASTraits> dir;
  return run.execute(dir);
}
