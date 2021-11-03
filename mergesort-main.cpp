/* Verbose Merge Sort 
   Created by Dr. Jan Pearce, Berea College
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printvec(vector<int> alist) {
    for (unsigned int i=0; i<alist.size(); i++) {
        cout << alist[i] << " ";
    }
    cout << endl;
}

vector<int> mergeSort(vector<int> alist) {
    cout << "Splitting: ";
    printvec(alist);
    if (alist.size()>1) {
        int mid = alist.size()/2;
        //C++ Equivalent to using Python Slices
        vector<int> lefthalf(alist.begin(),alist.begin()+mid);
        vector<int> righthalf(alist.begin()+mid,alist.begin()+alist.size());

        lefthalf = mergeSort(lefthalf);
        righthalf = mergeSort(righthalf);

        unsigned i = 0;
        unsigned j = 0;
        unsigned k = 0;
        while (i < lefthalf.size() && j < righthalf.size()) {
            if (lefthalf[i] < righthalf[j]) {
                alist[k]=lefthalf[i];
                i++;
            } else {
                alist[k] = righthalf[j];
                j++;
            }
            k++;
        }

        while (i<lefthalf.size()) {
            alist[k] = lefthalf[i];
            i++;
            k++;
        }

        while (j<righthalf.size()) {
            alist[k]=righthalf[j];
            j++;
            k++;
        }
    }
    cout<<"Merging:   ";
    printvec(alist);

    return alist;
}

int main() {
    // Vector initialized using a static array
    static const int arr[] = { 5, 8, 2, 4, 10, 6, 3, 7, 1 };
    vector<int> alist (arr, arr + sizeof(arr) / sizeof(arr[0]) );
	string inputme;

    cout  << "Initial:   ";
    printvec(alist);
    cout << "... " << endl;
    mergeSort(alist);
    cout << "Final:     ";
    printvec(alist);

	cin >> inputme;

    return 0;
}
