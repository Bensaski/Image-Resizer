// let's start with including libraries
#include<opencv2/opencv.hpp>
#include<iostream>
#include<windows.h>
#include<string.h>
#include <tchar.h>

#ifndef NOMINMAX
#define NOMINMAX
#endif

// Namespace to nullify use of cv::function(); syntax
using namespace std;
using namespace cv;
int height;
int width;
string image_path{};

Mat image{};

void resize(){
    // Read the image using imread function
	// let's downscale the image using new  width and height
	Mat resized_down;
	//resize down
	resize(image, resized_down, Size(width, height), INTER_LINEAR);
  imwrite(image_path, resized_down);
}


void open_file(){
	 char filename[ MAX_PATH ];

  OPENFILENAME ofn;
    ZeroMemory( &filename, sizeof( filename ) );
    ZeroMemory( &ofn,      sizeof( ofn ) );
    ofn.lStructSize  = sizeof( ofn );
    ofn.hwndOwner    = NULL;  // If you have a window to center over, put its HANDLE here
    ofn.lpstrFilter  = _T("Text Files\0*.txt\0Any File\0*.*\0");
    ofn.lpstrFile    = filename;
    ofn.nMaxFile     = MAX_PATH;
    ofn.lpstrTitle   = _T("Select a File, yo!");
    ofn.Flags        = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST;

  if (GetOpenFileName( &ofn ))
  {
    image_path = filename;
    image = imread(image_path);
    std::cout << "You chose the file \"" << filename << "\"\n";
  }
  else
  {
    // All this stuff below is to tell you exactly how you messed up above.
    // Once you've got that fixed, you can often (not always!) reduce it to a 'user cancelled' assumption.
    switch (CommDlgExtendedError())
    {
      case CDERR_DIALOGFAILURE   : std::cout << "CDERR_DIALOGFAILURE\n";   break;
      case CDERR_FINDRESFAILURE  : std::cout << "CDERR_FINDRESFAILURE\n";  break;
      case CDERR_INITIALIZATION  : std::cout << "CDERR_INITIALIZATION\n";  break;
      case CDERR_LOADRESFAILURE  : std::cout << "CDERR_LOADRESFAILURE\n";  break;
      case CDERR_LOADSTRFAILURE  : std::cout << "CDERR_LOADSTRFAILURE\n";  break;
      case CDERR_LOCKRESFAILURE  : std::cout << "CDERR_LOCKRESFAILURE\n";  break;
      case CDERR_MEMALLOCFAILURE : std::cout << "CDERR_MEMALLOCFAILURE\n"; break;
      case CDERR_MEMLOCKFAILURE  : std::cout << "CDERR_MEMLOCKFAILURE\n";  break;
      case CDERR_NOHINSTANCE     : std::cout << "CDERR_NOHINSTANCE\n";     break;
      case CDERR_NOHOOK          : std::cout << "CDERR_NOHOOK\n";          break;
      case CDERR_NOTEMPLATE      : std::cout << "CDERR_NOTEMPLATE\n";      break;
      case CDERR_STRUCTSIZE      : std::cout << "CDERR_STRUCTSIZE\n";      break;
      case FNERR_BUFFERTOOSMALL  : std::cout << "FNERR_BUFFERTOOSMALL\n";  break;
      case FNERR_INVALIDFILENAME : std::cout << "FNERR_INVALIDFILENAME\n"; break;
      case FNERR_SUBCLASSFAILURE : std::cout << "FNERR_SUBCLASSFAILURE\n"; break;
      default                    : std::cout << "You cancelled.\n";
    }
  }
}

int main()
{
	open_file();


	cout << "Enter height" << endl;
    cin >> height;
    cout << "Enter width" << endl;
    cin >> width;


	resize();

	// Display Images and press any key to continue



	return 0;
}


