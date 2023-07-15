namespace DDB
{
    class Vector
    {
    public:
        Vector(int sz);
        double& operator[](int i);
        int size();
    private:
        double* elem;
        int sz;
    };
}