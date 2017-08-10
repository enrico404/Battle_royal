OBJ = BRoyal.o init_object.o Map_module.o Draw_module.o Collision_manager.o Camera_Manager.o Shots_manager.o Weapons_generator.o
CXXFLAGS=-Wall

BRoyal: $(OBJ)
	g++ -g -o BRoyal $(OBJ) `pkg-config --libs allegro-5 allegro_dialog-5 allegro_font-5 allegro_ttf-5 allegro_primitives-5 allegro_image-5 allegro_audio-5 allegro_acodec-5`

-include dependencies

.PHONY: depend clean cleanall

depend:
	g++ -MM *.cc > dependencies
clean:
	rm *.o
cleanall:
	rm BRoyal *.o *~
