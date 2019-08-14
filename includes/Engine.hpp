#ifndef ENGINE_HPP
# define ENGINE_HPP

# include <iostream>
# include <list>

# include "IGameObject.hpp"
# include "SdlWindow.hpp"
# include "Time.hpp"
# include "Skybox.hpp"
# include "MeshRenderer.hpp"
# include "Framebuffer.hpp"

namespace Engine42
{
    class Engine 
    {

    public: 
    /*	constructors / destrucors	*/
        virtual ~Engine(void); 

    /*	public variables	*/
    /*	public functions	*/
        static void            AddMeshRenderer(std::list<MeshRenderer*> meshrenderer);
        static void            AddMeshRenderer(MeshRenderer *meshrenderer);
        static void            AddFramebuffer(Framebuffer *fbo);
        static void            SetWindow(const SdlWindow *win);
        static void            AddGameObject(Engine42::IGameObject *object);
        static void            AddGameObject(std::list<Engine42::IGameObject*> objects);
        static void            SetSkybox(Skybox *skybox);
        static void            Loop(void);
        static const SDL_Event &GetEvent();
        static const Uint8     *GetKeyInput();
        static bool             Destroy(MeshRenderer *meshRenderer);
        static void             ReloadShaders(void);
    private:
    /*  private constructor*/
        Engine(void); 
    /*	private variables	*/
        static Engine                       _inst;
        std::list<MeshRenderer *>           _meshRenderers;
        std::list<Framebuffer *>			_framebuffers;
        std::list<Shader*>                  _shaders;
        std::list<Engine42::IGameObject*>   _gameObjs;
        SDL_Event                           _event;
        const Uint8                         *_keys;
        const SdlWindow                     *_win;
        Skybox                              *_skybox;       
    /*	private functions	*/
        void                                _RenderAll(void);
        void                                _UpdateAll(void);
        void                                _FixedUpdateAll(void);

    };
}

#endif
