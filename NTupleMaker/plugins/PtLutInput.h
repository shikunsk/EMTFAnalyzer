
// ROOT includes
#include "TTree.h"
#include "TFile.h"

// CMSSW includes
#include "CommonTools/UtilAlgos/interface/TFileService.h"

// FWCore
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h" // Necessary for DEFINE_FWK_MODULE

// GEN particles
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"

// EMTF classes
#include "DataFormatsSep2016/L1TMuon/interface/EMTFHitExtra.h"
#include "DataFormatsSep2016/L1TMuon/interface/EMTFTrackExtra.h"

// Output tree branches
#include "EMTFAnalyzer/NTupleMaker/interface/PtLutInputBranches.hh"

// Helpful tools
#include "EMTFAnalyzer/NTupleMaker/interface/HelperFunctions.hh"

class PtLutInput : public edm::EDAnalyzer {

 public:
  
  // Constructor/destructor
  explicit PtLutInput(const edm::ParameterSet&);
  ~PtLutInput();
  
  // Default parameters
  float MIN_GEN_ETA   = 1.0;
  float MAX_GEN_ETA   = 2.5;
  
  // Structs for output tree
  GenMuonBranch _muon;
  EMTFHitBranch _hit;
  EMTFTrackBranch _track;

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
  edm::EDGetTokenT<std::vector<L1TMuonEndCap::EMTFHitExtra>> EMTFHit_token;
  edm::EDGetTokenT<std::vector<L1TMuonEndCap::EMTFTrackExtra>> EMTFTrack_token;
  
}; // End class PtLutInput public edm::EDAnalyzer

// Define as a plugin
DEFINE_FWK_MODULE(PtLutInput);
