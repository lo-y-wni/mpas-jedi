/*
 * (C) Copyright 2017 UCAR
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 */

#include "mpasjedi/Traits.h"
#include "oops/runs/Run.h"
#include "test/interface/UnstructuredInterpolator.h"


int main(int argc,  char ** argv) {
  oops::Run run(argc, argv);
  test::UnstructuredInterpolator<mpas::Traits> tests;
  return run.execute(tests);
}
