void wirechamber_kinematics() {
  //Open files
  TCanvas *canvas = new TCanvas("canvas", "canvas", 1200, 1500);
   TFile *f = new TFile("beam.root", "read");
   TTree *wc_1 = (TTree*)f->Get("VirtualDetector/wire_chamber_1_detector");
   TTree *wc_2 = (TTree*)f->Get("VirtualDetector/wire_chamber_2_detector");
   TTree *wc_3 = (TTree*)f->Get("VirtualDetector/wire_chamber_3_detector");
   TTree *wc_4 = (TTree*)f->Get("VirtualDetector/wire_chamber_4_detector");

   //creating histograms
   TH1F *h1 = new TH1F("h1", "x in wirechamber 3", 100, -100, 10);
   TH3* h2 = new TH3D("h2", "wirechamber 1;x(cm);y(cm);z(cm)", 100, -460, -330, 100, -60, 70, 100, 1700, 1740);
   TH3* h3 = new TH3D("h3", "wirechamber 1&2;x(cm);y(cm);z(cm)", 100, -800, -330, 100, -65, 70, 100, 1700, 3200);
   TH2* h4 = new TH2F("h4", "x difference, wirechamber 2&3; x(cm); y(cm)", 100, -1100 , -650, 100, -65, 65);
   TH3* h5 = new TH3D("h5", "wirechamber 2&3;x(cm);y(cm);z(cm)", 100, -1100, -650, 100, -65, 70, 100, 3100, 5200);
   
   //declare variables 
   Float_t x_wc1, y_wc1, z_wc1, xwc1[553], ywc1[553], zwc1[553];
   Float_t x_wc2, y_wc2, z_wc2, xwc2[553], ywc2[553], zwc2[553];
   Float_t x_wc3, y_wc3, z_wc3, xwc3[553], ywc3[553], zwc3[553];
   Float_t x_wc4, y_wc4, z_wc4, xwc4[553], ywc4[553], zwc4[553];
      
   wc_1->SetBranchAddress("x", &x_wc1);
   wc_1->SetBranchAddress("y", &y_wc1);
   wc_1->SetBranchAddress("z", &z_wc1);
   wc_2->SetBranchAddress("x", &x_wc2);
   wc_2->SetBranchAddress("y", &y_wc2);
   wc_2->SetBranchAddress("z", &z_wc2);
   wc_3->SetBranchAddress("x", &x_wc3);
   wc_3->SetBranchAddress("y", &y_wc3);
   wc_3->SetBranchAddress("z", &z_wc3);
   wc_4->SetBranchAddress("x", &x_wc4);
   wc_4->SetBranchAddress("y", &y_wc4);
   wc_4->SetBranchAddress("z", &z_wc4);  

  //Getting entries
  int k = 0;
  for (Int_t i = 0; i<553; i++) {
    wc_1->GetEntry(i);
   
    xwc1[i] = x_wc1;
    ywc1[i] = y_wc1;
    zwc1[i] = z_wc1;
    
    h2->Fill(x_wc1, y_wc1, z_wc1);
    h3->Fill(x_wc1, y_wc1, z_wc1);
  }
  
 for (Int_t i = 0; i<256; i++) {
   wc_2->GetEntry(i);

    xwc2[i] = x_wc2;
    ywc2[i] = y_wc2;
    zwc2[i] = z_wc2;
    h3->Fill(x_wc2, y_wc2, z_wc2);
    h4->Fill(x_wc2, y_wc2);
    h5->Fill(x_wc2, y_wc2, z_wc2);
    cout << x_wc2 << " " << y_wc2 << " " << z_wc2 << endl;
    //cout << xwc2[i] << " " << ywc2[i] << endl;
 
 }

 for (Int_t i = 0; i<2; i++) {
   wc_3->GetEntry(i);

    xwc3[i] = x_wc3;
    ywc3[i] = y_wc3;
    zwc3[i] = z_wc3;

    h3->Fill(x_wc3, y_wc3, z_wc3);
    h5->Fill(x_wc3, y_wc3, z_wc3);

    //cout << xwc3[i] << endl;
 }
 
  
    
  int n = 1106;
 
  h5->SetMarkerColor(kRed);
  h5->SetMarkerStyle(5);
  h5->SetFillColor(kRed);
  h5->Draw();
  h5->GetXaxis()->SetTitleOffset(2);
  h5->GetYaxis()->SetTitleOffset(2);
  h5->GetZaxis()->SetTitleOffset(1.5);
  
  //h4->GetXaxis()->SetTitle("x (cm)");
  //h4->GetXaxis()->SetTitleOffset(2);
  //h4->GetYaxis()->SetTitle("y (cm)");
  //h4->GetYaxis()->SetTitleOffset(2);
  //h4->Draw();
  
  canvas->Print("Wirechamber23_3D.pdf");
  canvas->Close();
  
}
