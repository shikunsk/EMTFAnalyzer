#ifndef FlatNtupleBranchesRecoMuonInfo_h
#define FlatNtupleBranchesRecoMuonInfo_h

//-------------------------------------------------------------------------------
// Create by Wei Shi
//-------------------------------------------------------------------------------
// Common branch info
#include "EMTFAnalyzer/NTupleMaker/interface/FlatNtupleBranches/Common.h"

//RECO
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/MuonReco/interface/Muon.h"
////////////////////////////////
///  RECO muon  information  ///
////////////////////////////////

struct RecoMuonInfo {
  std::vector<TString> ints = {{"nRecoMuons"}};
  std::vector<TString> vFlt = {{"reco_pt", "reco_eta", "reco_phi", "reco_St1_eta", "reco_St1_phi", "reco_St2_eta", "reco_St2_phi"}};
  std::vector<TString> vInt = {{"reco_charge", "reco_loose", "reco_medium", "reco_tight"}};
  std::map<TString, int> mInts;
  std::map<TString, std::vector<float> > mVFlt;
  std::map<TString, std::vector<int> > mVInt;

  void Initialize();
  void Reset();
  void Fill(reco::MuonCollection::const_iterator it, edm::Handle<reco::VertexCollection> vertices);
};

#endif
