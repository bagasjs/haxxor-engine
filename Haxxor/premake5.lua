project "Haxxor"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir "%{wks.location}/build/bin"
	objdir "%{wks.location}/build/bin-int/%{prj.name}"

	defines {
		"HX_BUILD_SHAREDLIB",
		"HX_EXPORT",
	}

	includedirs {
		"%{prj.location}/src",
		"%{prj.location}/src/Haxxor",
		"%{prj.location}/vendors/glfw/include",
		"%{prj.location}/vendors/glfw/include/GLFW",
		"%{prj.location}/vendors/glad/include",
		"%{prj.location}/vendors/glad/include/glad",
		"%{prj.location}/vendors/glad/include/KHR"		
	}

	files {
		"%{prj.location}/src/**.cpp",
		"%{prj.location}/src/**.h",
    }

	filter "system:linux"
		pic "On"

		systemversion "latest"

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		runtime "Release"
		optimize "on"
        symbols "off"