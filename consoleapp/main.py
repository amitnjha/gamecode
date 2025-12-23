import gi
gi.require_version("Gtk", "4.0")
from gi.repository import Gtk, Gdk
import subprocess
import os

class FullscreenApp(Gtk.Application):
    def __init__(self):
        super().__init__(application_id="org.example.FullscreenApp")
        self.connect("activate", self.on_activate)

    def on_activate(self, app):
        # Create a new application window
        self.window = Gtk.ApplicationWindow(application=app, title="Aaryans's Game Console")
        main_box = Gtk.Box(orientation=Gtk.Orientation.VERTICAL, spacing=10)
        # Make the window fullscreen

        main_box  = Gtk.Grid()
        self.window.fullscreen()

        # Add content to the window (optional)
        label = Gtk.Label(label="Select a game to play")
        #self.window.add_child(label)

        self.window.set_child(main_box)
        #print(dir(self.window))


        buttonPong = Gtk.Button(label="Pong with Joy")
        buttonPong.connect("clicked", self.on_button_clicked)

        dirs = os.listdir("/home/aaryan/Desktop/Games")
        dirlen =  len(dirs)
        rowcount = 0
        for index in range(0, dirlen, 2):
            buttonPong = Gtk.Button(label=dirs[index])
            buttonPong.connect("clicked", self.on_button_clicked)
            image = Gtk.Image(file= "/home/aaryan/git/gamecode/consoleapp/"+dirs[index]+'.png');
            buttonPong.set_child(image);
            buttonPong.set_size_request(200, 100)
            buttonPong._value = dirs[index]

            if index+1 < dirlen:
                buttonPong1 = Gtk.Button(label=dirs[index+1])
                buttonPong1.connect("clicked", self.on_button_clicked)
                image = Gtk.Image(file= "/home/aaryan/git/gamecode/consoleapp/"+dirs[index+1]+'.png');
                buttonPong1.set_size_request(200, 100)
                buttonPong1.set_child(image);
                
                buttonPong1._value = dirs[index+1]
            
            main_box.attach(buttonPong,  index/2, 0, 1, 1) # Col 0, Row 0, spans 1 col and 1 row
            if index+1 < dirlen:
                main_box.attach(buttonPong1, index/2, 1, 1, 1) # Col 1, Row 0
            #main_box.attach(buttonPong, 0, 1, 1, 1) # Col 0, Row 1
            #main_box.attach(buttonPong, 1, 1, 1, 1) # Col 1, Row 1

        # Add spacing between elements
        main_box.set_column_spacing(5)
        main_box.set_row_spacing(5)

        
        #main_box.append(label)
        #main_box.append(buttonPong)
        

        

        # Connect the "Escape" key press to exit fullscreen
        # We need a controller to handle keyboard events
        key_controller = Gtk.EventControllerKey()


        


        key_controller.connect("key-pressed", self.on_key_pressed)

        
        self.window.add_controller(key_controller)

        # Present the window to the user
        self.window.present()

    def on_button_clicked(self, widget):
        try:
            result = subprocess.run(["cd /home/aaryan/Desktop/Games/{}/ && ./{}".format(widget._value,widget._value)], capture_output=True, text=True, check=True, shell=True) #
            print(result.stdout)
        except subprocess.CalledProcessError as e:
            print(f"Command failed with error: {e.stderr}")

    
    def on_key_pressed(self, controller, keyval, keycode, state):
        # Check if the pressed key is the 'Escape' key (Gdk.KEY_Escape)
        if keyval == Gdk.KEY_Escape:
            if self.window.is_fullscreen():
                self.window.unfullscreen()
            return True # Event handled

        return False # Event not handled

def main():
    app = FullscreenApp()
    app.run(None)

if __name__ == "__main__":
    main()

