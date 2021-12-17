/*
 * (C) Copyright 2021 UCAR.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 */

#include <ostream>
#include <string>

#include "oops/util/Logger.h"

#include "mpasjedi/GeometryMPAS.h"
#include "mpasjedi/MPASTraits.h"
#include "mpasjedi/StateMPAS.h"
#include "mpasjedi/VariableChange/VariableChange.h"

namespace mpas {

// -------------------------------------------------------------------------------------------------

VariableChange::VariableChange(const Parameters_ & params, const GeometryMPAS & geometry) {
  // Create the variable change
  variableChange_.reset(VariableChangeFactory::create(geometry,
                        params.variableChangeParametersWrapper.variableChangeParameters.value()));
}

// -------------------------------------------------------------------------------------------------

VariableChange::~VariableChange() {}

// -------------------------------------------------------------------------------------------------

void VariableChange::changeVar(StateMPAS & x, const oops::Variables & vars) const {
  // Trace
  oops::Log::trace() << "VariableChange::changeVar starting" << std::endl;

  // If all variables already in incoming state just remove the no longer needed fields
  if (vars <= x.variables()) {
    x.updateVars(vars);
    oops::Log::info() << "VariableChange::changeVar done (identity)" << std::endl;
    return;
  }

  oops::Log::trace() << "VariableChange::changeVar, vars" << vars << std::endl;
  // Create output state
  StateMPAS xout(*x.geometry(), vars, x.time());

  // Call variable change
  variableChange_->changeVar(x, xout);

  // Update variable names
  x.updateVars(vars);

  // Copy data from temporary state
  x = xout;

  // Trace
  oops::Log::trace() << "VariableChange::changeVar done" << std::endl;
}

// -------------------------------------------------------------------------------------------------

void VariableChange::changeVarInverse(StateMPAS & x, const oops::Variables & vars) const {
  // Trace
  oops::Log::trace() << "VariableChange::changeVarInverse starting" << std::endl;

  // If all variables already in incoming state just remove the no longer needed fields
  if (vars <= x.variables()) {
    x.updateVars(vars);
    oops::Log::info() << "VariableChange::changeVarInverse done (identity)" << std::endl;
    return;
  }

  // Create output state
  StateMPAS xout(*x.geometry(), vars, x.time());

  // Call variable change
  variableChange_->changeVarInverse(x, xout);

  // Update variable names
  x.updateVars(vars);

  // Copy data from temporary state
  x = xout;

  // Trace
  oops::Log::trace() << "VariableChange::changeVarInverse done" << std::endl;
}

// -------------------------------------------------------------------------------------------------

void VariableChange::print(std::ostream & os) const {
  os << *variableChange_;
}

// -------------------------------------------------------------------------------------------------

}  // namespace mpas
