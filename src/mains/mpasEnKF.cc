/*
 * (C) Copyright 2023 UCAR
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 */

#include <oops/runs/LocalEnsembleDA.h>
#include <oops/runs/Run.h>

#include <ufo/instantiateObsErrorFactory.h>
#include <ufo/instantiateObsFilterFactory.h>
#include <ufo/instantiateObsLocFactory.h>
#include <ufo/ObsTraits.h>

#include "mpasjedi/Traits.h"

int main(int argc,  char ** argv) {
  oops::Run run(argc, argv);
  ufo::instantiateObsLocFactory<mpas::Traits>();
  ufo::instantiateObsErrorFactory();
  ufo::instantiateObsFilterFactory();

  oops::LocalEnsembleDA<mpas::Traits, ufo::ObsTraits> enkf;
  return run.execute(enkf);
}
