void Tof_kinematics() {
  //Open files
   TCanvas *canvas = new TCanvas("canvas");
   TFile *f = new TFile("beam.root", "read");
   TTree *tof_upstream = (TTree*)f->Get("VirtualDetector/tof_upstream");
   TTree *tof_downstream = (TTree*)f->Get("VirtualDetector/tof_downstream");
   
   //declare variables, create histograms   
   Float_t Px_us, Py_us, Pz_us, Px_tofus[1108],Py_tofus[1108], Pz_tofus[1108] ;
   TH1F *h1 = new TH1F("h1","Px for upstream TOF",100, -800, 10);
   tof_upstream->SetBranchAddress("Px", &Px_us);
   tof_upstream->SetBranchAddress("Py", &Py_us);
   tof_upstream->SetBranchAddress("Pz", &Pz_us);

   for (Int_t i = 0; i<1108; i++) {
    tof_upstream->GetEntry(i);
    Px_tofus[i] = Px_us;
    Py_tofus[i] = Py_us;
    Pz_tofus[i] = Pz_us;
    
    //cout << Px_tofus[i] << endl;
    
  }
   
   Float_t Px_ds, Py_ds, Pz_ds, Px_tofds[1108],Py_tofds[1108], Pz_tofds[1108] ;
   //TH1F *h2 = new TH1F("h1","Px for downstream TOF",100, -800, 10);
   tof_downstream->SetBranchAddress("Px", &Px_ds);
   tof_downstream->SetBranchAddress("Py", &Py_ds);
   tof_downstream->SetBranchAddress("Pz", &Pz_ds);
   
  for (Int_t i = 0; i<1108; i++) {
    tof_downstream->GetEntry(i);
    Px_tofds[i] = Px_ds;
    Py_tofds[i] = Py_ds;
    Pz_tofds[i] = Pz_ds;

    cout << Px_tofds[i] << endl;
    
  }

  
    
    
  }
