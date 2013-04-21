typedef unsigned int uint;
class TKkeys
{
public:
    TKkeys()
    {
        for (int i = 0; i < 255; i++)
        {
            _keys[i] = 0;
        }
    }
    ~TKkeys()
    {
        
    }

    bool isPressed(uint virKey)
    {
        if (virKey < 255)
        {
            return _keys[virKey] == 1;
        }
        return false;
    }

    void setPressed(uint virKey)
    {
        if (virKey < 255)
        {
            _keys[virKey] = 1;
        }
    }
    
    void setReleased(uint virKey)
    {
        if (virKey < 255)
        {
            _keys[virKey] = 0;
        }
    }
private:
    char _keys[255];
};