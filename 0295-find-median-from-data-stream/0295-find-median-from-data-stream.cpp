class MedianFinder {
public:
    priority_queue<int>maxi;
    priority_queue<int, vector<int>, greater<int>>mini;
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(maxi.empty() || maxi.top()> num){
            maxi.push(num);
        } 
        else{
            mini.push(num);
        }

        if(maxi.size()> mini.size()+1){
            mini.push(maxi.top());
            maxi.pop();
        }
        else if(maxi.size()+1< mini.size()){
            maxi.push(mini.top());
            mini.pop();
        }
    }
    
    double findMedian() {
        if(mini.size()==maxi.size()){
            return (maxi.top()+mini.top())/2.0;
        }
        else{
            return maxi.size()>mini.size() ? maxi.top(): mini.top();
        }
    }
};

// love babbar LC:77..detail explain

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */