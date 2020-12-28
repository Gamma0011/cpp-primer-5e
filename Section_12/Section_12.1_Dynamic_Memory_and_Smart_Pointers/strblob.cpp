#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <initializer_list>

class StrBlob {
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();          // default initializer;
    StrBlob(std::initializer_list<std::string> il): data(std::make_shared<std::vector<std::string>>(il)) { }
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    // add and remove elements
    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back();
    // element access
    std::string& front();
    std::string& back();
private:
    std::shared_ptr<std::vector<std::string>> data;
    // throws msg if data[i] invalid
    void check(size_type i, const std::string &msg) const;
};

void StrBlob::check(size_type i, const std::string &msg) const {
    if (i >= data->size()) {
        throw std::out_of_range(msg);
    }
}

std::string &StrBlob::front() {                     // return string by reference rather than by value (copy)
    // if vector empty, check will throw
    check(0, "Front on empty StrBlob");
    return data->front();
}

std::string &StrBlob::back() {                      // return string by reference rather than by value (copy)
    check(0, "Back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    return data->pop_back();
}

int main()
{

    return 0;
}