inherit ROOM;

void create()
{
	set("short", "�ƺ�����");
	set("long", @LONG
������Ƕ����������ƺ��ˣ�������ȥ����ɽ��Ұ��������������
Ū�����Լ����ںγ�������������ԼԼ��һ��С��ͨ��ǰ����ǰ����ǽ�
���ˣ�
LONG  );          
        set("exits",([
          "north": __DIR__"jinding",
              "south": __DIR__"yunhai12",
               ]));

	setup();  
	replace_program(ROOM);
}
