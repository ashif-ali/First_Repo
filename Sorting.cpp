#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n) {
	for(int i = 0; i<n; i++) {
		bool swaped = 1;
		for(int j = 0; j<n-i-1; j++) {
			if(arr[j] > arr[j+1]) {
				swap(arr[j], arr[j+1]);
				swaped = 0;
			}
		}
		if(swaped) break;
	}
}

void selectionSort(int arr[], int n) {
	for(int i = 0; i<n-1; i++) {
		int curr = i;
		for(int j = i+1; j<n; j++) {
			if(arr[curr] > arr[j]) curr = j;
		}
		swap(arr[curr], arr[i]);
	}
}

void insertionSort(int arr[], int n) {
	for(int i = 1; i<n; i++) {
		int j = i-1, temp = arr[i];
		while(j >= 0 and arr[j] > temp) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
	}
}

void merge(int arr[], int l, int r) {
	int mid = (l+r)/2;
	int i = mid + 1, j = l, k = 0;
	int temp[r-l+1];
	while(i <= r and j <= mid) {
		if(arr[i] < arr[j]) temp[k++] = arr[i++];
		else temp[k++] = arr[j++];
	}
	while(i <= r) temp[k++] = arr[i++];
	while(j <= mid) temp[k++] = arr[j++];
	for(i = l; i<=r; i++) {
		arr[i] = temp[i-l];
	}
}

void divide(int arr[], int l, int r) {
	if(l == r) return;
	int mid = (l+r)/2;
	divide(arr, l, mid);
	divide(arr, mid+1, r);
	merge(arr, l, r);
}

void mergeSort(int arr[], int n) {
	divide(arr, 0, n-1);
}

void quickS(int arr[], int l, int r) {
	if(l >= r) return;
	int piv = arr[r], i = l, j = r-1;
	while(i <= j) {
		while(i < j and arr[i] <= piv) i++;
		if(arr[j] <= piv) {
			swap(arr[j], arr[i]);
			i++;
		}
		j--;
	}
	swap(arr[i], arr[r]);
	quickS(arr, l, i - 1);
	quickS(arr, i+1, r);
}

void quickSort(int arr[], int n) {
	quickS(arr, 0, n-1);
}

class Heap {
    vector<int> max_heap;

    public:
    Heap() {
        max_heap.push_back(-1);
    }

    void insert_(int num) {
        max_heap.push_back(num);
        int i = max_heap.size()-1;
        while( i/2 > 0 and max_heap[i] > max_heap[i/2] ) {
            swap(max_heap[i/2], max_heap[i]);
            i /= 2;
        }
    }

    void delete_() {
        int i = max_heap.size()-1;
        if(i<1) return;
        swap(max_heap[1], max_heap[i]);
        max_heap.pop_back();
        i--;
        int temp = 1;
        while( temp*2 + 1 <= i ) {
            int mx, idx;
            if( max_heap[temp*2+1] > max_heap[temp*2] ) {
                mx = max_heap[temp*2+1];
                idx = temp*2+1;
            }
            else {
                mx = max_heap[temp*2];
                idx = temp*2;
            }

            if( mx > max_heap[temp] ) {
                swap(max_heap[idx], max_heap[temp]);
                temp = idx;
            }
            else break;
        }

        if(temp*2 <= i and max_heap[temp] < max_heap[temp*2]) {
            swap(max_heap[temp], max_heap[temp*2]);
        }


    }

    int top_() {
        return max_heap[1];
    }

    bool isEmpty() {
        return (max_heap.size() <= 1);
    }


};

void heapSort(int arr[], int n) {
	Heap hp;
	for(int i = 0; i<n; i++) {
		hp.insert_(arr[i]);
	}
	int i = n-1;
	while(!hp.isEmpty()) {
		arr[i--] = hp.top_();
		hp.delete_();
	}
}

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i<n; i++) cin>>arr[i];
	heapSort(arr, n);
	for(int i:arr) cout<<i<<' ';
}