inherit ITEM;
#include <ansi.h>

void create()
{
  set_name(HIW"����"NOR, ({"bing fu", "pai"}));
  set_weight(10);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "֧");
    set("long", @LONG
           ����
         ��    ��
         �� �� ��
         �� �� ��
         �� �� ��
         �� ɽ ��
         ��    ��
         �� �� ��
         ��    ��
          ������
LONG);
        }
  setup();
}
