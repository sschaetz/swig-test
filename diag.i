%module diagswig
%{
#include "diag.hpp"
%}

%ignore diag::diag();

// Parse original header.
#include "diag.hpp"

