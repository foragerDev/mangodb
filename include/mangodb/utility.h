

namespace mangodb
{
    template <typename T>
    bool is_power_of_two(T &value)
    {
        return (value != 0) && ((value & value - 1) == 0);
    }
}
