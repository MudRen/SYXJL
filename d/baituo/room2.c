//room1.c
inherit ROOM;
void create()
{
  set("short","������");
  set("long",
      "�����ǰ���ɽ���ӵ������ҡ�������ͭ������������\n"
    );
  set("exits",([
      "out" : __DIR__"liangong",
     ]));

 set("objects",([
        "/d/heimuya/npc/tong-ren":2,
     ]));
 set_temp("full",0);
 setup();

}

void init()
{ object ob=this_player();
  if((int)query_temp("full")==3)
   {
    message_vision("$Nһ���������Ѿ������ˣ�ֻ�����˳�ȥ��\n",ob);
    ob->move(__DIR__"liangong");
    return;
   }
  add_temp("full" ,1);
  return;
}

int valid_leave(object who, string dir)
{
 add_temp("full",-1);
 return 1;
}
