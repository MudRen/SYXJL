// yield.c
// Emperor@SDXL add this command in 99.2.8.

int main(object me, string arg)
{
                        if (arg=="yes") {
                     me->set("yield",1);
                     me->reset_action();
                     write("�����ֻ�мܣ������֡�\n");
                     return 1;
                }
                  else if (arg=="no") {
                 me->delete("yield");
                 me->reset_action();
                 write("�������ʼ���֡�\n");
                 return 1;
           }

                  else  write("�����ʽ��yield [ yes|no ].\n");
                 return 1;
      }
