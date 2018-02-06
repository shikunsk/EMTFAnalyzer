
// ROOT includes
#include "TTree.h"
#include "TFile.h"

// So vectors can be written out in the tree branch
#include "TROOT.h"
#include <vector>

// CMSSW includes
#include "CommonTools/UtilAlgos/interface/TFileService.h"

// FWCore
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h" // Necessary for DEFINE_FWK_MODULE

// Output branches
#include "EMTFAnalyzer/NTupleMaker/interface/FlatNtupleBranches/EventInfo.h"
#include "EMTFAnalyzer/NTupleMaker/interface/FlatNtupleBranches/GenMuonInfo.h"
#include "EMTFAnalyzer/NTupleMaker/interface/FlatNtupleBranches/EMTFHitInfo.h"
#include "EMTFAnalyzer/NTupleMaker/interface/FlatNtupleBranches/EMTFTrackInfo.h"
#include "EMTFAnalyzer/NTupleMaker/interface/FlatNtupleBranches/EMTFUnpTrackInfo.h"
#include "EMTFAnalyzer/NTupleMaker/interface/FlatNtupleBranches/RecoMuonInfo.h"

class FlatNtuple : public edm::EDAnalyzer {

 public:
  
  // Constructor/destructor
  explicit FlatNtuple(const edm::ParameterSet&);
  ~FlatNtuple();

  /* // Default constants */
  /* const int   DINT = -999; */
  /* const float DFLT = -999.; */
  
  // Default parameters
  const float MIN_GEN_ETA   = 1.0;
  const float MAX_GEN_ETA   = 2.5;

  ///////////////////////////////////
  ///  Output branch information  ///
  ///////////////////////////////////
  EventInfo eventInfo;
  GenMuonInfo genMuonInfo;
  EMTFHitInfo emtfHitInfo;
  EMTFTrackInfo emtfTrackInfo;
  EMTFUnpTrackInfo emtfUnpTrackInfo;
  RecoMuonInfo recoMuonInfo;

  // Output tree
  TTree * out_tree;

 private:
  
  // Inherited from EDAnalyzer
  virtual void beginJob();
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endJob();
  
  // File in/out
  edm::Service<TFileService> fs;
  
  // Config parameters
  bool isMC;
  
  // EDM Tokens
  edm::EDGetTokenT<std::vector<reco::GenParticle>> GenMuon_token;
  edm::EDGetTokenT<std::vector<l1t::EMTFHit>> EMTFHit_token;
  edm::EDGetTokenT<std::vector<l1t::EMTFTrack>> EMTFTrack_token;
  edm::EDGetTokenT<std::vector<l1t::EMTFTrack>> EMTFUnpTrack_token;
  edm::EDGetTokenT<L1Analysis::L1AnalysisRecoMuon2&> RecoMuon_token;
  
}; // End class FlatNtuple public edm::EDAnalyzer

// Define as a plugin
DEFINE_FWK_MODULE(FlatNtuple);
