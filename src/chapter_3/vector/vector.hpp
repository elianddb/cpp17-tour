namespace DDB
{
    class Vector
    {
    public:
        Vector(int size);
        double& operator[](int index);
        int size();
    private:
        double* elem;
        int sz;
    };
}