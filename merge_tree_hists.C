void merge_tree_hists() {
  TCanvas *canvas = new TCanvas("canvas", "canvas", 500, 600);
    TChain *chain = new TChain("EventTree_Spill1");
    //double TrackID_values[8];
    TH1* hist = new TH1D("ParticleID histogram", "ParticleID histogram", 100, -30, 30);
    chain->Add("merge_tree.root");
    double PDGidnova, ;
    chain->SetBranchAddress("PDGidnova", &PDGidnova);

    auto entries = chain->GetEntries();
    
    for (int i=0; i<entries; i++){
       chain->GetEntry(i);
       //cout << TPDGidnova << endl;
       //TrackID_values[i] = TrackID;
      hist->Fill(PDGidnova);
     }

    //TH1D *hist = new TH1D("TrackID histogram", "TrackID histogram", 990, 1900);
    //hist->Fill(TrackID_values);
    hist->Draw();
    canvas->Print("PDGid_30limits.png");
    canvas->Close();
    
  }
