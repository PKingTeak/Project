#include "EngineCore.h"
#include "EngineDebug.h"

void EngineCore::Init(int2 _ScreenSize)
{
    LeakCheck;

	Screen.CreateScreen(/*&NewScreen => this, */20, 20); //원래 메인에서 화면 크기를 할당했었다 이것을 엔진 코어에 가져왔음
}

void EngineCore::Start()
{ //메인에 있던 while문이다. 즉 게임의 통제를 하는 기능이다. 
    while (EngineUpdate)
    {
        // 밀리세컨드 단위
        Sleep(100);

        // 업데이트
        { //오브젝트들을 맵으로 관리하여 구분하기 위한 업데이트
            //맵으로 관리한다 이유는 맵을 이용하면 같은 분류의 오브젝트끼리 관리를 할수있기 때문이다.
            //list<ConsoleObject> = 모든 오브젝트를 가지고 있는 통합오브젝트이다.
            std::map<int, std::list<ConsoleObject*>>::iterator OrderStartIter = AllUpdateObject.begin(); // 순회 하기 위해 innerclass인 iterator를 사용하여 시작값과 끝값을 정함
            std::map<int, std::list<ConsoleObject*>>::iterator OrderEndIter = AllUpdateObject.end();

            for (; OrderStartIter != OrderEndIter; ++OrderStartIter)
            {
                std::list<ConsoleObject*>& ObjectList = OrderStartIter->second; //리스트의 값을 저장하는것이다 그래서 StartIter가 가르키는 키가 아닌 값을 넣어야 하기 때문에 first가 아닌 second를 넣었다.
                

                std::list<ConsoleObject*>::iterator StartIter = ObjectList.begin(); //첫번째 노드를 가르키면서 노드 순환 
                std::list<ConsoleObject*>::iterator EndIter = ObjectList.end(); // 마지막 노드를 가르키는 포인터 
                for (; StartIter != EndIter; ++StartIter)
                {
                    ConsoleObject* Object = *StartIter; //오브젝트라는 ConsoleObject클래스의포인터 형으로 선언하여 StartIter의 값을 가르키는 주소값을 가르키게 한다.
                    //이렇게 선언하는 이유는 결국 포인터도 함수이기때문에
                    //원래는 StartIter.operator*()실행되는것이기 때문에 이러면 함수를 여러번 호출하는 방식이 된다. 이렇게 되면 메모리 공간을 계속 할당해 줘야 하기 때문에 
                    //값을 받아서 사용하는것이 메모리효율도 좋아지면서 사용하기도 편해진다. 또한 디버깅을 할때 값을 확인하면서 사용을 할 수 있다.


                    if (nullptr == Object)
                    {
                        MsgBoxAssert("오브젝트가 nullptr인 경우가 존재합니다.");
                    }

                    Object->Update(); //요거 이해가 안된다.
                    //이거는 console엔진에가면 비어있다 하지만
                    //플레이어가 그것을 오버라이드하여 사용하고 있기때문에 Object는 결국
                    //플레이어에게 가게된다. 
                }
            }
        }

        // 랜더링
        //랜더링은 화면에 그려주는것을 담당하기 때문에 오브젝트오더를 위해 만들었다. 그리고 각 함
        {
            std::map<int, std::list<ConsoleObject*>>::iterator OrderStartIter = AllRenderObject.begin();
            std::map<int, std::list<ConsoleObject*>>::iterator OrderEndIter = AllRenderObject.end();

            for (; OrderStartIter != OrderEndIter; ++OrderStartIter)
            {
                std::list<ConsoleObject*>& ObjectList = OrderStartIter->second;

                std::list<ConsoleObject*>::iterator StartIter = ObjectList.begin();
                std::list<ConsoleObject*>::iterator EndIter = ObjectList.end();
                for (; StartIter != EndIter; ++StartIter)
                {
                    ConsoleObject* Object = *StartIter;

                    if (nullptr == Object)
                    {
                        MsgBoxAssert("오브젝트가 nullptr인 경우가 존재합니다.");
                    }

                    Screen.SetChar(Object);
                }
            }
        }

        Screen.PrintScreen(); //화면에 출력


        //// 랜더 릴리즈 구조
        {
            std::map<int, std::list<ConsoleObject*>>::iterator OrderStartIter = AllRenderObject.begin();
            std::map<int, std::list<ConsoleObject*>>::iterator OrderEndIter = AllRenderObject.end();

            for (; OrderStartIter != OrderEndIter; ++OrderStartIter)
            {
                std::list<ConsoleObject*>& ObjectList = OrderStartIter->second; //값에 접근

                std::list<ConsoleObject*>::iterator StartIter = ObjectList.begin();
                std::list<ConsoleObject*>::iterator EndIter = ObjectList.end();
                // 리스트의 삭제 방식을 배우셔야 합니다.
                for (; StartIter != EndIter; )
                { //릴리즈 할때 위에 코드들과 다르게 증감연산이 없는이유는
                    //리스트는 노드형식이기때문에 노드를 지우게 되면 자연스럽게 다음노드를 가르키게 된다 하지만
                    //여기에 ++StartIter 가 있다면 노드 한개를 건너뛰기 때문에 릭이 발생하게 된다. 
                    ConsoleObject* Object = *StartIter;

                    if (false == Object->IsPendingKill()) //오브젝트가 죽었는지 확인하는 조건문
                    {
                        ++StartIter;
                        continue;
                    }

                    if (nullptr == Object)
                    {
                        MsgBoxAssert("오브젝트가 nullptr인 경우가 존재합니다.");
                    }

                    //여기에 값을 지우는 delete가 없는 이유는 
                    //지금 코드를 보면 object값을 포인터로 가르키는 코드가 두개 존재한다 하지만 여기서 값을 지우게 되면
                    //아래 코드의 업데이트 포인터는 아무것도 없는 곳을 가르키게 되기 때문에 여기서는 랜더포인터만 지워주는것이다.


                    // 노드를 지운것.
                    StartIter = ObjectList.erase(StartIter);
                }
            }
        }

        //// 업데이트 릴리즈 구조
        {
            std::map<int, std::list<ConsoleObject*>>::iterator OrderStartIter = AllUpdateObject.begin();
            std::map<int, std::list<ConsoleObject*>>::iterator OrderEndIter = AllUpdateObject.end();

            for (; OrderStartIter != OrderEndIter; ++OrderStartIter)
            {
                std::list<ConsoleObject*>& ObjectList = OrderStartIter->second;

                std::list<ConsoleObject*>::iterator StartIter = ObjectList.begin();
                std::list<ConsoleObject*>::iterator EndIter = ObjectList.end();
                // 리스트의 삭제 방식을 배우셔야 합니다.
                for (; StartIter != EndIter; )
                {
                    ConsoleObject* Object = *StartIter;

                    if (false == Object->IsPendingKill())
                    {
                        ++StartIter;
                        continue;
                    }

                    if (nullptr == Object)
                    {
                        MsgBoxAssert("오브젝트가 nullptr인 경우가 존재합니다.");
                    }

                    delete Object;
                    Object = nullptr;
                    //값을 여기서 지우는 이유 
                    // 어느곳에서 지워도 상관없지만 그래도 업데이트가 가장 마지막에 종료되기 때문에 값을 여기서 지우게 된다.

                    // 노드를 지운것.
                    StartIter = ObjectList.erase(StartIter);
                }
            }
        }
    }

    {
        {
            std::map<int, std::list<ConsoleObject*>>::iterator OrderStartIter = AllUpdateObject.begin();
            std::map<int, std::list<ConsoleObject*>>::iterator OrderEndIter = AllUpdateObject.end();

            for (; OrderStartIter != OrderEndIter; ++OrderStartIter)
            {
                std::list<ConsoleObject*>& ObjectList = OrderStartIter->second;

                std::list<ConsoleObject*>::iterator StartIter = ObjectList.begin();
                std::list<ConsoleObject*>::iterator EndIter = ObjectList.end();
                // 리스트의 삭제 방식을 배우셔야 합니다.
                for (; StartIter != EndIter; ++StartIter)
                {
                    ConsoleObject* Object = *StartIter;
                    if (nullptr != Object)
                    {
                        delete Object;
                        Object = nullptr;
                    }
                }
            }
        }
        AllUpdateObject.clear();
    }
}