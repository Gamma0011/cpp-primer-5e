class Example {
public:
    static constexpr double rate = 6.5;     // fixed, declared constexpr
    static const int vecSize = 20;
    static std::vector<double> vec;              // removed vecSize from vec(vecSize)
};