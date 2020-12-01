// taken from page 494
#include <memory> // unique_ptr
#include <string>
#include <iostream> // cout
using std::unique_ptr; using std::string; using std::cout; using std::make_unique;

// example hierarchy
class Component {};
class Label : public Component {};
class Textfield : public Component {};
class Button : public Component {
public:
    int id_;
    explicit Button(int id) : id_{id} {}
};

class Window {};
class MyDialog : public Window {
    string title_;
    // use make_unique instad of contructor
    unique_ptr<Label> lblFirstName_ = make_unique<Label>();
    unique_ptr<Textfield> txtFirstName_ = make_unique<Textfield>();

    unique_ptr<Label> lblLastName_ = make_unique<Label>();
    unique_ptr<Textfield> txtLastName_ = make_unique<Textfield>();

    unique_ptr<Button> btnOk_ = make_unique<Button>(1);
    unique_ptr<Button> btnAbort_ = make_unique<Button>(2);
public:
    explicit MyDialog(const string& title) : title_{title} {}
    // reanamed
    unique_ptr<Button> showModal() {
        return std::move(btnOk_);
    }
};

unique_ptr<MyDialog> createDialog()
{
    return unique_ptr<MyDialog>{new MyDialog{"Bitte namen eingeben"}}; // temp var
}

int showDialog() {
    unique_ptr<MyDialog> dialog = createDialog();
    unique_ptr<Button> btnPressed = dialog->showModal();

    // and now what you should NOT do
    // segfault. sice move* stole the pointer from the other unique_ptr and put it 
    // into a unique_ptr the field is not null
    // and that is what gets returned
    //*move actually only allows to steal
    auto btnPressed2 = dialog->showModal();
    // you need this so the last line does not get optimized away
    cout << btnPressed2->id_;


    return btnPressed->id_;
}

int main() {
    int pressedId = showDialog();
    if (pressedId == 1) {
        cout << "'Ok' was pressed\n";
    }
}