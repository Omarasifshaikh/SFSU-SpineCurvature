#include <iostream>
#include <vtkMetaImageReader.h>
#include <vtkSmartPointer.h>
#include <vtkResliceImageViewer.h>

using namespace std;

double seedX, seedY, seedZ;
double seedEnd, seedStart;

int main(int argc, char *argv[]) {
    cout << "Hello, World!" << endl;


    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " InputFile1\n" << "InputFile2\n";
        return EXIT_FAILURE;
    }

    vtkSmartPointer<vtkMetaImageReader> reader = vtkSmartPointer<vtkMetaImageReader>::New();
    reader->SetFileName(argv[1]);
    reader->Update();

    //display

    vtkSmartPointer<vtkResliceImageViewer> imageViewer = vtkSmartPointer<vtkResliceImageViewer>::New();
    imageViewer->SetInputConnection(reader->GetOutputPort());

    imageViewer->SetColorLevel(500);
    imageViewer->SetColorWindow(2000);
    seedZ = (imageViewer->GetSliceMax()) / 2;
    while (42) {
        //cout<<"current seed:"<<seedZ<<endl;


        //set z coord always the most center slice
        seedStart = imageViewer->GetSliceMin();
        seedEnd = imageViewer->GetSliceMax();



        //imageViewer->SetSize(512,512);
        imageViewer->SetSlice(seedZ);
        imageViewer->SetSliceOrientationToXY();
        imageViewer->Render();
        seedZ++;
        if (seedZ>seedEnd){
            seedZ = seedStart;
        }
    }

    return 0;
}