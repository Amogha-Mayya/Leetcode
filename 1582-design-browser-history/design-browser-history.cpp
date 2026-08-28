class BrowserHistory {
public:
    stack<string>backward,foward;
    BrowserHistory(string homepage) {
        backward.push(homepage);
    }
    
    void visit(string url) {
        foward = stack<string>();
        backward.push(url);
    }
    
    string back(int steps) {
        while(steps-- && backward.size() > 1){
            foward.push(backward.top());
            backward.pop();
        }
        return backward.top();
    }
    
    string forward(int steps) {
        while(steps-- && !foward.empty()){
            backward.push(foward.top());
            foward.pop();
        }
        return backward.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */