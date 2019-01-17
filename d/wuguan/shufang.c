
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "�鷿");
        set("long", @LONG
������ݹ������鷿�����ںܾ�����������Ӵ����������ֱ�����,
���ڿ�������һ������ܣ���Ȼ����Щ���˳������顣ǽ�ϸ����ż�����
�֡���׳��Ŭ�����ϴ�ͽ�˱�����
LONG);
        set("exits", ([
                "west" : __DIR__"changlang4",
        ]));    
        setup();
}
void init()
{
        add_action("do_clean", ({"fan","��","find"}));
}

int do_clean(string arg)
{
     object me,ob; 
     int i;
     i = random(50);
     me=this_player();
     
     if(!arg || arg != "���" ) return 0;

     if (me->query_temp("book_get")){
           message_vision("$NͻȻ�����Լ���ô��ô̰������һ����Ҫ�á�\n", me); 
           return 1;
           }
     if(!me->query_temp("wg_study")){
          message_vision("$N���ַ��˷���\n", me);
          return 1;
          }
   
     if(i < 6){
          message_vision("$N���˵�����������������һ���Լ���Ҫ���顣\n", me);
          switch(random(4)) {
              case 0:  ob=new("/d/wuguan/obj/book1"); break;
              case 1:  ob=new("/d/kunlun/obj/force-book"); break;
              case 2:  ob=new("/d/wudang/obj/daodejing-i"); break;
              }
          ob->move(me); 
          me->delete_temp("wg_study");
          me->set_temp("book_get",1);
          }
     else message_vision("$N���˰���û�����Լ���Ҫ�ġ�\n", me);
     me->receive_damage("jingli", random(5));
     return 1;
}
