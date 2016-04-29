# template_factory

### Macros
```cpp
DECLARE_COMPONENT(className)
```
Simply adds a static string as a member variable that holds the class name as a value.

```cpp
REGISTER_COMPONENT(className, scriptName)
```
Creates an anonymous namespace that defines the functions needed by the factory for registering classes derived from component.

### Creating Components
```cpp
#include "component.h"

class MyComponent : public Component {
	DECLARE_COMPONENT(MyComponent);

public:
	MyComponent();
	~MyComponent();
};

REGISTER_COMPONENT(MyComponent, mycomponent);
```
