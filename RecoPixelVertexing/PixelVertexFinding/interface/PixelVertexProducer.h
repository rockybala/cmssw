#ifndef PixelVertexFinding_PixelVertexProducer_h
#define PixelVertexFinding_PixelVertexProducer_h
// -*- C++ -*-
//
// Package:    PixelVertexProducer
// Class:      PixelVertexProducer
// 
/**\class PixelVertexProducer PixelVertexProducer.h PixelVertexFinding/interface/PixelVertexProducer.h

 Description: This produces 1D (z only) primary vertexes using only pixel information.

 Implementation:
     This producer can use either the Divisive Primary Vertex Finder
     or the Histogramming Primary Vertex Finder (currently not
     implemented).  It relies on the PixelTripletProducer and
     PixelTrackProducer having already been run upstream.   This is
     code ported from ORCA originally written by S Cucciarelli, M
     Konecki, D Kotlinski.
*/
//
// Original Author:  Aaron Dominguez (UNL)
//         Created:  Thu May 25 10:17:32 CDT 2006
//

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "DataFormats/BeamSpot/interface/BeamSpot.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"

class DivisiveVertexFinder;

class PixelVertexProducer : public edm::EDProducer {
 public:
  explicit PixelVertexProducer(const edm::ParameterSet&);
  ~PixelVertexProducer();

  virtual void produce(edm::Event&, const edm::EventSetup&);
 private:
  // ----------member data ---------------------------
  // Turn on debug printing if verbose_ > 0
  int verbose_;
  DivisiveVertexFinder *dvf_;
  // Tracking cuts before sending tracks to vertex algo
  double ptMin_;
  edm::InputTag trackCollName;
  edm::EDGetTokenT<reco::TrackCollection> token_Tracks;
  edm::EDGetTokenT<reco::BeamSpot> token_BeamSpot;
  bool method2;

};
#endif
