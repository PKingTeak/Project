#include "EngineCore.h"
#include "EngineDebug.h"

void EngineCore::Init(int2 _ScreenSize)
{
    LeakCheck;

	Screen.CreateScreen(/*&NewScreen => this, */20, 20); //���� ���ο��� ȭ�� ũ�⸦ �Ҵ��߾��� �̰��� ���� �ھ ��������
}

void EngineCore::Start()
{ //���ο� �ִ� while���̴�. �� ������ ������ �ϴ� ����̴�. 
    while (EngineUpdate)
    {
        // �и������� ����
        Sleep(100);

        // ������Ʈ
        { //������Ʈ���� ������ �����Ͽ� �����ϱ� ���� ������Ʈ
            //������ �����Ѵ� ������ ���� �̿��ϸ� ���� �з��� ������Ʈ���� ������ �Ҽ��ֱ� �����̴�.
            //list<ConsoleObject> = ��� ������Ʈ�� ������ �ִ� ���տ�����Ʈ�̴�.
            std::map<int, std::list<ConsoleObject*>>::iterator OrderStartIter = AllUpdateObject.begin(); // ��ȸ �ϱ� ���� innerclass�� iterator�� ����Ͽ� ���۰��� ������ ����
            std::map<int, std::list<ConsoleObject*>>::iterator OrderEndIter = AllUpdateObject.end();

            for (; OrderStartIter != OrderEndIter; ++OrderStartIter)
            {
                std::list<ConsoleObject*>& ObjectList = OrderStartIter->second; //����Ʈ�� ���� �����ϴ°��̴� �׷��� StartIter�� ����Ű�� Ű�� �ƴ� ���� �־�� �ϱ� ������ first�� �ƴ� second�� �־���.
                

                std::list<ConsoleObject*>::iterator StartIter = ObjectList.begin(); //ù��° ��带 ����Ű�鼭 ��� ��ȯ 
                std::list<ConsoleObject*>::iterator EndIter = ObjectList.end(); // ������ ��带 ����Ű�� ������ 
                for (; StartIter != EndIter; ++StartIter)
                {
                    ConsoleObject* Object = *StartIter; //������Ʈ��� ConsoleObjectŬ������������ ������ �����Ͽ� StartIter�� ���� ����Ű�� �ּҰ��� ����Ű�� �Ѵ�.
                    //�̷��� �����ϴ� ������ �ᱹ �����͵� �Լ��̱⶧����
                    //������ StartIter.operator*()����Ǵ°��̱� ������ �̷��� �Լ��� ������ ȣ���ϴ� ����� �ȴ�. �̷��� �Ǹ� �޸� ������ ��� �Ҵ��� ��� �ϱ� ������ 
                    //���� �޾Ƽ� ����ϴ°��� �޸�ȿ���� �������鼭 ����ϱ⵵ ��������. ���� ������� �Ҷ� ���� Ȯ���ϸ鼭 ����� �� �� �ִ�.


                    if (nullptr == Object)
                    {
                        MsgBoxAssert("������Ʈ�� nullptr�� ��찡 �����մϴ�.");
                    }

                    Object->Update(); //��� ���ذ� �ȵȴ�.
                    //�̰Ŵ� console���������� ����ִ� ������
                    //�÷��̾ �װ��� �������̵��Ͽ� ����ϰ� �ֱ⶧���� Object�� �ᱹ
                    //�÷��̾�� ���Եȴ�. 
                }
            }
        }

        // ������
        //�������� ȭ�鿡 �׷��ִ°��� ����ϱ� ������ ������Ʈ������ ���� �������. �׸��� �� ��
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
                        MsgBoxAssert("������Ʈ�� nullptr�� ��찡 �����մϴ�.");
                    }

                    Screen.SetChar(Object);
                }
            }
        }

        Screen.PrintScreen(); //ȭ�鿡 ���


        //// ���� ������ ����
        {
            std::map<int, std::list<ConsoleObject*>>::iterator OrderStartIter = AllRenderObject.begin();
            std::map<int, std::list<ConsoleObject*>>::iterator OrderEndIter = AllRenderObject.end();

            for (; OrderStartIter != OrderEndIter; ++OrderStartIter)
            {
                std::list<ConsoleObject*>& ObjectList = OrderStartIter->second; //���� ����

                std::list<ConsoleObject*>::iterator StartIter = ObjectList.begin();
                std::list<ConsoleObject*>::iterator EndIter = ObjectList.end();
                // ����Ʈ�� ���� ����� ���ž� �մϴ�.
                for (; StartIter != EndIter; )
                { //������ �Ҷ� ���� �ڵ��� �ٸ��� ���������� ����������
                    //����Ʈ�� ��������̱⶧���� ��带 ����� �Ǹ� �ڿ������� ������带 ����Ű�� �ȴ� ������
                    //���⿡ ++StartIter �� �ִٸ� ��� �Ѱ��� �ǳʶٱ� ������ ���� �߻��ϰ� �ȴ�. 
                    ConsoleObject* Object = *StartIter;

                    if (false == Object->IsPendingKill()) //������Ʈ�� �׾����� Ȯ���ϴ� ���ǹ�
                    {
                        ++StartIter;
                        continue;
                    }

                    if (nullptr == Object)
                    {
                        MsgBoxAssert("������Ʈ�� nullptr�� ��찡 �����մϴ�.");
                    }

                    //���⿡ ���� ����� delete�� ���� ������ 
                    //���� �ڵ带 ���� object���� �����ͷ� ����Ű�� �ڵ尡 �ΰ� �����Ѵ� ������ ���⼭ ���� ����� �Ǹ�
                    //�Ʒ� �ڵ��� ������Ʈ �����ʹ� �ƹ��͵� ���� ���� ����Ű�� �Ǳ� ������ ���⼭�� ���������͸� �����ִ°��̴�.


                    // ��带 �����.
                    StartIter = ObjectList.erase(StartIter);
                }
            }
        }

        //// ������Ʈ ������ ����
        {
            std::map<int, std::list<ConsoleObject*>>::iterator OrderStartIter = AllUpdateObject.begin();
            std::map<int, std::list<ConsoleObject*>>::iterator OrderEndIter = AllUpdateObject.end();

            for (; OrderStartIter != OrderEndIter; ++OrderStartIter)
            {
                std::list<ConsoleObject*>& ObjectList = OrderStartIter->second;

                std::list<ConsoleObject*>::iterator StartIter = ObjectList.begin();
                std::list<ConsoleObject*>::iterator EndIter = ObjectList.end();
                // ����Ʈ�� ���� ����� ���ž� �մϴ�.
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
                        MsgBoxAssert("������Ʈ�� nullptr�� ��찡 �����մϴ�.");
                    }

                    delete Object;
                    Object = nullptr;
                    //���� ���⼭ ����� ���� 
                    // ��������� ������ ��������� �׷��� ������Ʈ�� ���� �������� ����Ǳ� ������ ���� ���⼭ ����� �ȴ�.

                    // ��带 �����.
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
                // ����Ʈ�� ���� ����� ���ž� �մϴ�.
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