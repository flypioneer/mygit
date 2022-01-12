/**
 * Observer Design Pattern
 *
 * Intent: Lets you define a subscription mechanism to notify multiple objects
 * about any events that happen to the object they're observing.
 *
 * Note that there's a lot of different terms with similar meaning associated
 * with this pattern. Just remember that the Subject is also called the
 * Publisher and the Observer is often called the Subscriber and vice versa.
 * Also the verbs "observe", "listen" or "track" usually mean the same thing.
 */

#include<iostream>
#include<list>
#include<string>

class IObserver{
    public:
    virtual ~IObserver(){};
    virtual void Update(const std::string &message_from_subject) = 0;
};

class ISubject{
    public:
    virtual ~ISubject(){};
    virtual void Attach(IObserver *observer) = 0;
    virtual void Detach(IObserver *observer) = 0;
    virtual void Notify() = 0;
};

/**
 * The Subject owns some important state and notifies observers when the state
 * changes.
 */

class Subject: public ISubject{
    public:
    virtual ~Subject(){
        std::cout << "Goodbye, I was the Subject.\n";
    }
    /* The subscription management methods.*/

    void Attach(IObserver *observer) override{
        list_observer_.push_back(observer);
    }
    void Detach(IObserver *observer) override{
        list_observer_.remove(observer);
    
    }
    void Notify() override{
        std::list<IObserver *>::iterator iterator = long
        HowManyObserver();
        while (iterator != list_observer_.end()){
            (*iterator)->Update(message_);
            ++iterator;
        }

    }
    void CreateMessage(std::string message = "Empty"){
       this->message_ = message;
       Notify(); 
    }
    void HowManyObserver(){
        std::cout<< "There are "<< list_observer_.size()<< "observers in the list.\n";
    }

    /**
   * Usually, the subscription logic is only a fraction of what a Subject can
   * really do. Subjects commonly hold some important business logic, that
   * triggers a notification method whenever something important is about to
   * happen (or after it).
   */
  void SomeBusinessLogic(){
      this->message_ = "change message message";
      Notify();
      std::cout << "I'm about to do some thing important\n";
  }


  private:
  std::list<IObserver *> list_observer_;
  std::string message_;
};

class Observer : public IObserver {
    public:
    Observer(Subject &subject) : subject_(subject) {
        this->subject_.Attach(this);
        std::cout<<"Hi, I'm the Observer \"" << ++Observer::static_number_ << "\".\n";
        this->number_ = Observer::static_number_;

    }
    virtual ~Observer() {
        std::cout << ""
    }
}
