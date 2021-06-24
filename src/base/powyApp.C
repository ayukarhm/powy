#include "powyApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
powyApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

powyApp::powyApp(InputParameters parameters) : MooseApp(parameters)
{
  powyApp::registerAll(_factory, _action_factory, _syntax);
}

powyApp::~powyApp() {}

void
powyApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"powyApp"});
  Registry::registerActionsTo(af, {"powyApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
powyApp::registerApps()
{
  registerApp(powyApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
powyApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  powyApp::registerAll(f, af, s);
}
extern "C" void
powyApp__registerApps()
{
  powyApp::registerApps();
}
