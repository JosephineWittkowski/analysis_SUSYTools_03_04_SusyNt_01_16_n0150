// emacs -*- C++ -*-
#ifndef SUSY_WH_TUPLEMAKEROBJECTS_H
#define SUSY_WH_TUPLEMAKEROBJECTS_H

#include "/data/etp3/jwittkow/analysis_SUSYTools_03_04/SusyNtuple/SusyNtuple/SusyNt.h"

#include <iostream>
#include <vector>

namespace susy
{
namespace wh
{

  using Susy::Lepton;
  using Susy::Jet;
  using Susy::Met;
struct FourMom {
    double px, py, pz, E;
    bool isMu, isEl, isJet;
    FourMom() : px(0), py(0), pz(0), E(0), isMu(false), isEl(false), isJet(false) {}
#ifndef __CINT__
// cint is not able to parse 'complex' code; see
// http://root.cern.ch/drupal/content/interacting-shared-libraries-rootcint
    FourMom& set4mom(const Lepton &l) { px=l.Px(); py=l.Py(); pz=l.Pz(); E=l.E(); return *this; }
    FourMom& set4mom(const Jet &j)    { px=j.Px(); py=j.Py(); pz=j.Pz(); E=j.E(); return *this; }
    FourMom& setMu(const Lepton &l) { isMu=true; isEl = isJet = false; return set4mom(l); }
    FourMom& setEl(const Lepton &l) { isEl=true; isMu = isJet = false; return set4mom(l); }
    FourMom& setJet(const Jet &j)   { isJet=true; isMu = isEl = false; return set4mom(j); }
    FourMom& setMet(const Met &m)   { isJet=isMu=isEl=false; px=m.lv().Px(); py=m.lv().Py(); E=m.lv().E(); return *this; }
#endif
};

struct EventParameters {
    double weight;
    unsigned int eventNumber;
    unsigned int runNumber;
    EventParameters() : weight(0), eventNumber(0), runNumber(0) {}
#ifndef __CINT__
    EventParameters& setWeight(const double &w) { weight=w; return *this; }
    EventParameters& setEvent(const unsigned int &e) { eventNumber=e; return *this; }
    EventParameters& setRun(const unsigned int &r) { runNumber=r; return *this; }
#endif
};

} // namespace wh
} // namespace susy

#endif // end include guard
