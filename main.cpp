void merge_sort(vector<int *> &left, vector<int *> &right) {
    vector<int> dst;
    int left_pos, right_pos;
    left_pos = right_pos = 0;

    for (auto l: left) cout << "left: " << *l << endl;
    for (auto r: right) cout << "right: " << *r << endl;
    cout << "one loop" << endl<<endl;

    while (left_pos < left.size() and right_pos < right.size()) {
        if (*left[left_pos] < *right[right_pos]) {
            dst.push_back(*left[left_pos]);
            left_pos++;
        } else {
            dst.push_back(*right[right_pos]);
            right_pos++;
        }
    }

    while (left_pos < left.size()) {
        dst.push_back(*left[left_pos++]);
    }
    while (right_pos < right.size()) {
        dst.push_back(*right[right_pos++]);
    }

    for (int i = 0; i < dst.size(); ++i) {
        if (i < left.size()) *left[i] = dst[i];
        else *right[i - (int) left.size()] = dst[i];
    }
}

void msort(vector<int *> &arr) {
    if (arr.size() <= 1) return;

    int mid = ((int) arr.size() + 1) / 2;
    vector<int *> left{arr.begin(), arr.begin() + mid};
    vector<int *> right{arr.begin() + mid, arr.end()};

    msort(left);
    msort(right);

    merge_sort(left, right);
}

//迭代法实现归并
void msort_(vector<int *> &arr) {

    int N = (int) arr.size();
    for (int j = 1; j < N; j *= 2) {
        for (int i = 0; i < N;) {
            int l_pos = std::min(N, i + j);
            int r_pos = std::min(N, i + 2 * j);

            vector<int *> left(&arr[i], &arr[l_pos]);
            vector<int *> right(&arr[min(i + j, N)], &arr[r_pos]);

            merge_sort(left, right);
            i += 2 * j;
        }
    }
}

int main(){
  
    vector<int>ms{5,4,3,2,1};
    vector<int*>msPtr;

    for(auto &mv:ms) msPtr.emplace_back(&mv);
    msort(msPtr);

    for(auto s:ms) cout<<"Dst: "<<s<<endl;
}
